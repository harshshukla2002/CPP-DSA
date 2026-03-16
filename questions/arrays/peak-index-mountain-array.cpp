/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

2 solutions 1 - linear search, 2 - binary search(optimised)
*/

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &nums)
{
    int st = 1, end = nums.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] > nums[mid - 1])
            st = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> nums = {0, 3, 8, 9, 5, 2};

    return 0;
}