#ifndef NODE_H
#define NODE_H

#include<vector>

template<typename K, typename V>
class Node {
public:
    K key;
    V value;
    int node_level;
    std::vector<Node<K, V>*> forward;

    Node(K k, V v, int level) : key(k), value(v), node_level(level) {
        this->forward.resize(level + 1, nullptr);
    }

    ~Node() {}
};

#endif