#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    map<pair<int, int>, int> dp;

    int backtrack(int i, int total, vector<int>& nums, int target) {
        // Base case
        if (i == nums.size()) {
            return (total == target) ? 1 : 0;
        }

        // Check memoization
        pair<int, int> key = {i, total};

        if (dp.count(key)) {
            return dp[key];
        }

        // Two choices: + or -
        dp[key] = backtrack(i + 1, total + nums[i], nums, target) +
                  backtrack(i + 1, total - nums[i], nums, target);

        return dp[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return backtrack(0, 0, nums, target);
    }
};