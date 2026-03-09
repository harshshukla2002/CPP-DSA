/*
Question: Maximum Sum Subarray
*/

#include <iostream>
#include <vector>
using namespace std;

// brute force ---
int maxSubArray(vector<int> &num, int n)
{
    int maxSum = INT_MIN;

    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += num[end];
            maxSum = max(currSum, maxSum);
        }
    }

    return maxSum;
}

// Kadane's Algorithm
int maxSubArray2(vector<int> &nums)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int val : nums)
    {
        currSum += val;
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main()
{
    vector<int> num = {3, -4, 5, 4, -1, 7, -8};
    int n = num.size();
    int res = maxSubArray(num, n);
    cout << res << endl;
    return 0;
}