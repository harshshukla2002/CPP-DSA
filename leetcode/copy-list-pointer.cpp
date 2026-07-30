#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;

        oldToCopy[nullptr] = nullptr;

        Node* cur = head;

        // First pass: Create copy of each node
        while (cur) {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;

        // Second pass: Connect next and random pointers
        while (cur) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }

        return oldToCopy[head];
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}