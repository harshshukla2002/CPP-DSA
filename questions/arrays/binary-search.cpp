#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (target > nums[mid])
            st = mid + 1;
        else if (target < nums[mid])
            end = mid - 1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 6, 7, 8, 9, 12};
    int target = 0;

    cout << binarySearch(nums, target) << endl;

    return 0;
}