/*
Question: WAF to print nth fibonacci
*/
#include <iostream>
using namespace std;

int nFibonacci(int n)
{
    int curr;
    int prev1 = 1;
    int prev2 = 0;

    for (int i = 0; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    cout << "Nth fabonacci is: " << nFibonacci(10) << endl;

    return 0;
}