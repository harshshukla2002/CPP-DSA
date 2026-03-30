#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int index = st - 1, pivot = arr[end];

    for (int j = 0; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(arr[j], arr[index]);
        }
    }

    index++;
    swap(arr[end], arr[index]);
    return index;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivot = partition(arr, st, end);

        quickSort(arr, st, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    vector<int> arr = {12, 37, 18, 8, 25, 32};
    quickSort(arr, 0, arr.size() - 1);
    return 0;
}