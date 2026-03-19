#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);
    dq.pop_back();

    for (int l : dq)
    {
        cout << l << " " << endl;
    }

    cout << endl;
    return 0;
}