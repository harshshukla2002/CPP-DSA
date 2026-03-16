#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int> &arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

bool isValid(vector<int> &arr, int n, int m, int maxAllow)
{
    int stu = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllow)
            return false;

        if (pages + arr[i] <= maxAllow)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;

    int st = 0, end = getSum(arr, n);
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> books = {2, 1, 3, 4};
    int n = 4;
    int m = 2;

    cout << allocateBooks(books, n, m) << endl;
    return 0;
}