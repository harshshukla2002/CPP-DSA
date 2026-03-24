#include <iostream>
using namespace std;

void printNum(int n)
{
    // base case
    if (n == 1)
    {
        cout << n << endl;
        return;
    }

    cout << n << " ";
    printNum(n - 1);
}

int main()
{
    printNum(5);
    return 0;
}