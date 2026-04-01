#include <iostream>
using namespace std;

ListNode *middleLinkedList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}