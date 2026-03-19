#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ls;

    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);
    ls.pop_back();

    for (int l : ls)
    {
        cout << l << " " << endl;
    }

    cout << endl;
    return 0;
}