#include <iostream>
#include <vector>
using namespace std;

int main()
{
    pair<int, char> p = {1, '1'};
    vector<pair<int, int>> vec = {{1, 2}, {3, 4}};

    for (pair<int, int> p : vec) // or we can use auto instead of pair<int, int>
    {
    }

    cout << p.first << endl;
    return 0;
}