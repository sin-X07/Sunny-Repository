#include<iostream>
#include<string>

using namespace std;

struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v) : key(k), value(v), next(nullptr) {}
};

class SimpleList {
private:
    Node* head;

public:
    SimpleList() {
        head = new Node(-1, "LIST_HEAD");
    }

    void insertNode(int key, string value) {
        Node* newNode = new Node(key, value);
        Node* curr = head;

        while (curr->next != nullptr && key > curr->next->key) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;

        return;
    }

    void deleteNode(int key) {
        Node* curr = head;
        
        while (curr->next != nullptr && key != curr->next->key) {
            curr = curr->next;
        }
        if (curr->next == nullptr) {
            cout << "Not Exist " << key << " In List" << endl;
            return; 
        }
        Node* target = curr->next;
        curr->next = target->next;
        delete target;
        
        return;
    }

    void searchNode(int key) {
        Node* curr = head->next;

        while (curr != nullptr) {
            if (curr->key == key) {
                cout << curr->key << ":" << curr->value << endl;
                return;
            } else {
                curr = curr->next;
            }
        }

        cout << "Not Exist " << key << " In List" << endl;

        return;
    }
};

int main() {
    SimpleList SL;

    SL.insertNode(1, "a");
    SL.insertNode(2, "b");
    SL.insertNode(3, "c");
    SL.deleteNode(2); // 只删除中间的
    SL.searchNode(1); // 应该存在
    SL.searchNode(3); // 应该存在
    SL.searchNode(2); // 应该不存在

    return 0;
}