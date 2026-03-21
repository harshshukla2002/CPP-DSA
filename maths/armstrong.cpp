#include <iostream>
using namespace std;

bool armStrong(int n)
{
    int sum = 0;
    int num = n;

    while (n > 0)
    {
        int dig = n % 10;
        int cube = dig * dig * dig;
        sum += cube;

        n /= 10;
    }

    return sum == num;
}

int main()
{
    int n = 111;
    string ans = armStrong(n) ? "Yes" : "No";

    cout << ans << endl;
    return 0;
}