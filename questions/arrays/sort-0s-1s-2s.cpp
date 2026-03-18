#include <iostream>
#include <vector>
using namespace std;

/*
Question: Sort numbers as 0,1,2
solutions -> 1. Brute Force -> using sort function
2. Optimal -> count 0,1 and 2 then put according to count
3. Optimized -> Dutch National Flag Algorithm
*/

vector<int> sortArrays(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high--]);
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = {2, 2, 0, 0, 1, 1, 0, 1, 0, 2};

    return 0;
}