#include <iostream>
using namespace std;

int linearSearch(int num[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (num[i] == target)
            return i;
    }

    return -1;
}

int main()
{
    int num[6] = {4, 6, 7, 3, 2, 7};
    int size = 6;
    int target = 8;

    int ans = linearSearch(num, size, target);

    cout << "Target is: " << ans << endl;

    return 0;
}