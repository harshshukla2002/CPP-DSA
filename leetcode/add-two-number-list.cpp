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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int v1 = (l1) ? l1->val : 0;
            int v2 = (l2) ? l2->val : 0;

            // Calculate new digit
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            cur->next = new ListNode(sum);
            cur = cur->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy.next;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}