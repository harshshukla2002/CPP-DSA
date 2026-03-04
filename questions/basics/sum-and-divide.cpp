// Question: Sum of all number from 1 to N which is divible by 3;

#include <iostream>
using namespace std;

int main()
{
    int N = 10;
    int sum = 0;

    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0)
        {
            cout << i << endl;
            sum += i;
        }
    }

    cout << "total sum is: " << sum << endl;

    return 0;
}