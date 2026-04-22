#include<iostream>
#include<vector>

template <typename K, typename V>
class Node {
public:
    K key;
    V value;
    int node_level;
    Node<K, V> **forward;

    Node(K k, V v, int level) : key(k), value(v), node_level(level) {
        this->forward = new Node<K, V>*[level + 1];
        for (int i=0; i<=level; i++) {
            this->forward[i] = nullptr;
        }
    }

    ~Node() {
        delete[] forward;
    }
};