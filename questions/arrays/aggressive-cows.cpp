#include <iostream>
#include <vector>
using namespace std;

int isPossible(vector<int> &nums, int n, int c, int maxAllow)
{
    int cows = 1, lastPos = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] - lastPos >= maxAllow)
        {
            cows++;
            lastPos = nums[i];
        }

        if (cows == c)
            return true;
    }

    return false;
}

int getDistance(vector<int> &nums, int n, int c)
{
    sort(nums.begin(), nums.end());
    int ans = -1;
    int st = 1, end = nums[n - 1] - nums[0];

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(nums, n, c, mid))
        {
            ans = mid;
            st = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 8, 4, 9};
    int c = 3, n = 5;

    cout << getDistance(nums, n, c) << endl;
    return 0;
}