#include <iostream>
#include <list>
using namespace std;

class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }

    void pop()
    {
        ll.pop_front();
    }

    int top()
    {
        return ll.front();
    }

    bool isEmpty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}