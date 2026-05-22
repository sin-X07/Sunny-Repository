#ifndef SKIPLIST_H
#define SKIPLIST_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<shared_mutex>
#include"node.h"

template<typename K, typename V>
class SkipList {
private:
    int MAX_LVL;
    int current_lvl;
    Node<K, V>* header;
    int element_count;
    std::ofstream wal_file;
    std::shared_mutex rw_mtx;

    int get_random_level() {
        int lvl = 0;
        while (rand() % 2 == 0 && lvl < MAX_LVL) lvl++;
        return lvl;
    }

public:
    SkipList(int max_lvl) : MAX_LVL(max_lvl), current_lvl(0), element_count(0) {
        header = new Node<K, V>(K(), V(), MAX_LVL);
        wal_file.open("wal.log", std::ios::out | std::ios::app);
    }

    ~SkipList() {
        Node<K, V>* current = header->forward[0];

        while (current != nullptr) {
            Node<K, V>* next_node = current->forward[0];
            delete current;
            current = next_node;
        }
        delete header;

        if (wal_file.is_open()) wal_file.close();
    }

    bool insert_element(K key, V value, bool write_wal = true);
    bool search_element(K key, V& value);
    bool delete_element(K key, bool write_wal = true);
    void display_list();
    int size() { return element_count; }
    void dump_file(std::string file_path);
    void load_file(std::string file_path);
    void replay_wal();
};

template<typename K, typename V>
bool SkipList<K, V>::insert_element(K key, V value, bool write_wal) {
    std::unique_lock<std::shared_mutex> write_lock(rw_mtx);

    Node<K, V>* current = header;
    std::vector<Node<K, V>*> update(MAX_LVL + 1, nullptr);

    for (int i = current_lvl; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    if (current && current->key == key) {
        current->value = value;
        return false;
    }

    int random_level = get_random_level();
    if (random_level > current_lvl) {
        for (int i = current_lvl + 1; i <= random_level; i++) {
            update[i] = header;
        }
        current_lvl = random_level;
    }

    Node<K, V>* inserted_node = new Node<K, V>(key, value, random_level);

    for (int i = 0; i <= random_level; i++) {
        inserted_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = inserted_node;
    }
    
    if (write_wal && wal_file.is_open()) {
        wal_file << "SET:" << key << ":" << value << "\n";
        wal_file.flush();
    }

    element_count++;

    return true;
}

template<typename K, typename V>
bool SkipList<K, V>::search_element(K key, V& value) {
    std::shared_lock<std::shared_mutex> read_lock(rw_mtx); 

    Node<K, V>* current = header;

    for (int i = current_lvl; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];

    if (current && current->key == key) {
        value = current->value;
        return true;
    }
    return false;
}

template<typename K, typename V>
bool SkipList<K, V>::delete_element(K key, bool write_wal) {
    std::unique_lock<std::shared_mutex> write_lock(rw_mtx);

    Node<K, V>* current = header;
    std::vector<Node<K, V>*> update(MAX_LVL + 1, nullptr);

    for (int i = current_lvl; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    if (!current) return false;

    if (current->key == key) {
        for (int i = 0; i <= current_lvl; i++) {
            if (update[i]->forward[i] != current) break;
            else update[i]->forward[i] = current->forward[i];
        }
        delete current;

        while (current_lvl > 0 && header->forward[current_lvl] == nullptr) current_lvl--;
        
        if (write_wal && wal_file.is_open()) {
            wal_file << "DEL:" << key << ":\n";
            wal_file.flush();
        }

        element_count--;
        return true;
    }

    return false;
}

template<typename K, typename V>
void SkipList<K, V>::display_list() {
    std::shared_lock<std::shared_mutex> read_lock(rw_mtx);

    std::cout << "\n==== Skip List 内存架构视图 ====\n";
    for (int i = current_lvl; i >= 0; i--) {
        Node<K, V>* node = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << "[" << node->key << ":" << node->value << "] -> ";
            node = node->forward[i];
        }
        std::cout << "nullptr\n";
    }
    std::cout << "===============================\n\n";
}

template<typename K, typename V>
void SkipList<K, V>::dump_file(std::string file_path) {
    std::unique_lock<std::shared_mutex> write_lock(rw_mtx);

    std::ofstream file(file_path, std::ios::out);

    Node<K, V>* current = header->forward[0];

    while (current != nullptr) {
        file << current->key << ":" << current->value << "\n";
        current = current->forward[0];
    }

    file.close();
    std::cout << "[Dump 成功]：内存数据已成功固化到磁盘文件：" << file_path << std::endl;

    if (wal_file.is_open()) wal_file.close();
    wal_file.open("wal.log", std::ios::out | std::ios::trunc);
    wal_file.close();

    wal_file.open("wal.log", std::ios::out | std::ios::app);
}

template<typename K, typename V>
void SkipList<K, V>::load_file(std::string file_path) {
    std::ifstream file(file_path, std::ios::in);
    if (!file.is_open()) {
        std::cout << "[Load 提示]：未找到快照文件 " << file_path << ", 跳表以空内存启动。" << std::endl;
        return;
    }

    std::string line;
    int loaded_count = 0;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t colon_pos = line.find(":");
        std::string key_str = line.substr(0, colon_pos);
        std::string val_str = line.substr(colon_pos + 1);

        K key = std::stoi(key_str);
        V value = val_str;

        this->insert_element(key, value, false);
        loaded_count++;
    }

    file.close();
    std::cout << "[Load 成功]：成功从磁盘文件恢复了 " << loaded_count << " 条数据到内存条表中！" << std::endl;
}

template<typename K, typename V>
void SkipList<K, V>::replay_wal() {
    if (wal_file.is_open()) wal_file.close();
    std::ifstream file("wal.log", std::ios::in);
    if (!file.is_open()) return;

    std::string line;
    int replay_count = 0;

    std::cout << "[WAL 日志追踪]：发现历史 WAL 日志， 正在重放数据以恢复位同步的内存...\n";

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t first_colon = line.find(':');
        std::string cmd = line.substr(0, first_colon);
 
        std::string kv_part = line.substr(first_colon + 1);
        size_t second_colon = kv_part.find(':');

        std::string key_str = kv_part.substr(0, second_colon);
        std::string val_str = kv_part.substr(second_colon + 1);

        if (cmd == "SET") {
            K key;
            std::stringstream ss(key_str);
            ss >> key;
            V value = val_str;

            this->insert_element(key, value, false);
            replay_count++;
        } else if (cmd == "DEL") {
            K key;
            std::stringstream ss(key_str);
            ss >> key;

            this->delete_element(key, false);
            replay_count++;
        }

        wal_file.open("wal.log", std::ios::out | std::ios::app);
    }

    file.close();
    std::cout << "[WAL 重放成功]：成功重放了 " << replay_count << " 条实时操作，内存已恢复至断电前的绝对最新状态！\n";
}

#endif