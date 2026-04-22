#include"node.h"

template <typename K, typename V> 
class SkipList {
private:
    int _max_level;
    int _skip_list_level;
    int _element_count;
    Node<K, V> *_header;

public:
    SkipList(int max_level) : _max_level(max_level), _skip_list_level(0), _element_count(0) {
        K k;
        V v;
        this->_header = new Node<K, V>(k, v, max_level);
    }

    ~SlipList() {

        delete _header;
    }

    int get_random_level() {
        
    }
    int insert_element(K, V);
    bool search_element(K, V&);
    void delete_element(K);
};