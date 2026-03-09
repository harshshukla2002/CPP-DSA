#include <iostream>
#include <vector>
using namespace std;

// brute force
vector<int> pairSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

// two pointer - for sorted arrays
vector<int> pairSum(vector<int> &nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;
    vector<int> ans = {};

    while (st < end)
    {
        int sum = nums[st] + nums[end];
        if (sum < target)
            st++;
        else if (sum > target)
            end--;
        else
        {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = pairSum(nums, target);

    cout << "[" << ans[0] << "," << ans[1] << ']' << endl;

    return 0;
}