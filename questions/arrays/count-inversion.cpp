#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for (int index = 0; index < temp.size(); index++)
    {
        arr[index + st] = temp[index];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int leftCount = mergeSort(arr, st, mid);
        int rightCount = mergeSort(arr, mid + 1, end);
        int invCount = merge(arr, st, mid, end);

        return leftCount + rightCount + invCount;
    }

    return 0;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}