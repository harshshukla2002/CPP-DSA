#include <iostream>
using namespace std;

void reverseArray(int num[], int size)
{
    int rev[5];
    int index = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        rev[index++] = num[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << rev[i] << endl;
    }
}

// using two pointer approach
void revTwoPointer(int num[], int size)
{
    int st = 0;
    int end = size - 1;

    while (st < end)
    {
        swap(num[st++], num[end--]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << num[i] << endl;
    }
}

int main()
{
    int num[5] = {1, 2, 3, 4, 5};
    int size = 5;

    revTwoPointer(num, size);

    return 0;
}