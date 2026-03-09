#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
int majorityElement(vector<int> &nums)
{
    for (int val : nums)
    {
        int freq = 0;
        for (int el : nums)
        {
            if (el == val)
                freq++;
        }

        if (freq == nums.size() / 2)
            return val;
    }

    return -1;
}

// optimal approach
int majorityElement2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int ans = nums[0], freq = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }
    }

    return ans;
}

// moore's voting algorithm
int majorityElement3(vector<int> &nums)
{

    int ans = 0, freq = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
            ans = nums[i];

        if (ans == nums[i])
            freq++;
        else
            freq--;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}