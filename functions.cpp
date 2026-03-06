#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int ans = sum(2, 3);

    cout << "Sum is: " << ans << endl;

    return 0;
}
