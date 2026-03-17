#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i], prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

int main()
{
    vector<int> arr = {1, 4, 3, 2, 5};
    int n = 5;

    return 0;
}