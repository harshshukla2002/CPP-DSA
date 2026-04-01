#include <iostream>
using namespace std;

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        return NULL;
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}