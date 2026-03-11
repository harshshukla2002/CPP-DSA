#include <iostream>
using namespace std;

// time complexity -> O(n)
int powerN(int x, int n)
{
    int ans = x;

    for (int i = 1; i < n; i++)
    {
        ans *= x;
    }

    return ans;
}

// optimised using binary exponancial = O(logn)
int powerN2(int x, int n)
{
    long binForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }
    double ans = 1;

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= x;
        }

        x *= x;
        binForm /= 2;
    }

    return ans;
}

int main()
{
    cout << "Power of 2^5: " << powerN(2, 5) << endl;
    return 0;
}