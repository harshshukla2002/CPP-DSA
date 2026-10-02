#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    unordered_map<Node*, Node*> oldToNew;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        // If already cloned, return the existing clone
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a clone of the current node
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // Clone all neighbors
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};