#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 1. Reach the node at position 'left'
        ListNode* leftPrev = dummy;
        ListNode* cur = head;

        for (int i = 0; i < left - 1; i++) {
            leftPrev = cur;
            cur = cur->next;
        }

        // 2. Reverse the sublist from left to right
        ListNode* prev = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* tempNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tempNext;
        }

        // 3. Connect the reversed sublist back
        leftPrev->next->next = cur;
        leftPrev->next = prev;

        return dummy->next;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}