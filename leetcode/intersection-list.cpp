#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while (l1 != l2) {
            l1 = (l1 != nullptr) ? l1->next : headB;
            l2 = (l2 != nullptr) ? l2->next : headA;
        }

        return l1;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}