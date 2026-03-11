/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <iostream>
#include <vector>
using namespace std;

// brute force approach
vector<int> productArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        int mul = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                mul *= nums[j];
            }
        }
        ans.push_back(mul);
    }

    return ans;
}

vector<int> productArray2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productArray(nums);
    return 0;
}