#include <iostream>
#include <vector>
using namespace std;

int selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallest])
                smallest = j;
        }

        swap(arr[i], arr[smallest]);
    }
}

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    int n = 5;

    return 0;
}