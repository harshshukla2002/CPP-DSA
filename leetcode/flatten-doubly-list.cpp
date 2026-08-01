#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
   public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }

   private:
    Node* dfs(Node* head) {
        Node* cur = head;
        Node* last = nullptr;

        while (cur) {
            Node* next = cur->next;

            // If current node has a child
            if (cur->child) {
                Node* childHead = cur->child;
                Node* childTail = dfs(childHead);

                // Connect current node with child
                cur->next = childHead;
                childHead->prev = cur;
                cur->child = nullptr;

                // Connect child's tail with next node
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
            } else {
                last = cur;
            }

            cur = next;
        }

        return last;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}