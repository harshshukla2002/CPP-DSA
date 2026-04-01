#include <iostream>
using namespace std;

ListNode *mergeList(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return head1 == NULL ? head2 : head1;
    }

    if (head1->val <= head2->val)
    {
        head1->next = mergeList(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeList(head1, head2->next);
        return head2;
    }
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}