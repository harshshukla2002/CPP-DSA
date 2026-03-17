#include <iostream>
#include <vector>
using namespace std;

int getSum(vector<int> &nums, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += nums[i];

    return sum;
}

int getMax(vector<int> &nums, int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }

    return max;
}

bool isValid(vector<int> &nums, int n, int m, int maxAllow)
{
    int painter = 1, board = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxAllow)
            return false;

        if (nums[i] + board <= maxAllow)
            board += nums[i];
        else
        {
            painter++;
            board = nums[i];
        }
    }

    return painter > m ? false : true;
}

int painterPartition(vector<int> &nums, int n, int m)
{
    int st = getMax(nums, n);
    int end = getSum(nums, n);
    int minTime = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(nums, n, m, mid))
        {
            minTime = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return minTime;
}

int main()
{
    vector<int> nums = {40, 30, 20, 10};
    int m = 2, n = 4;

    cout << painterPartition(nums, n, m) << endl;
    return 0;
}