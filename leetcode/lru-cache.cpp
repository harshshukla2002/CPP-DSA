#include <iostream>
using namespace std;

class LRUCache {
   public:
    class Node {
       public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node* left;   // Least Recently Used (LRU)
    Node* right;  // Most Recently Used (MRU)

    LRUCache(int capacity) {
        this->capacity = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    // Remove a node from the list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    // Insert a node before the right dummy (MRU position)
    void insert(Node* node) {
        Node* prev = right->prev;

        prev->next = node;
        node->prev = prev;

        node->next = right;
        right->prev = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];

        // Move to MRU position
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            cache.erase(key);
            delete node;
        }

        Node* newNode = new Node(key, value);

        cache[key] = newNode;
        insert(newNode);

        // Remove LRU if capacity exceeded
        if (cache.size() > capacity) {
            Node* lru = left->next;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}