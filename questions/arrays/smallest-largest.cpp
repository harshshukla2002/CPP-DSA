#include <iostream>
using namespace std;

int findSmallest(int num[], int size)
{
    int smallest = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (smallest > num[i])
            smallest = num[i];

        // another way ---
        // smallest = min(num[i], smallest);
    }

    return smallest;
}

int findLargest(int num[], int size)
{
    int largest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (largest < num[i])
            largest = num[i];

        // another way ---
        // largest = max(num[i], largest);
    }

    return largest;
}

int main()
{
    int num[5] = {3, 2, 5, 6, 1};
    int largest = findLargest(num, 5);
    int smallest = findSmallest(num, 5);

    cout << "Largest : " << largest << " Smallest: " << smallest << endl;

    return 0;
}