#include <iostream>
using namespace std;

Node *flatten(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->child != NULL)
        {
            // flatten the node
            Node *next = curr->next;
            curr->next = flatten(curr->child);

            curr->next->prev = curr;
            curr->child = NULL;

            // find tail
            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            // attach tail node
            if (next != NULL)
            {
                curr->next = next;
                next->prev = curr;
            }
        }

        curr = curr->next;
    }

    return head;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}