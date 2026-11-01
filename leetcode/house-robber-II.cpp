#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    int helper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;

        for (int i = start; i < end; i++) {
            int n = nums[i];

            int newRob = max(rob1 + n, rob2);

            rob1 = rob2;
            rob2 = newRob;
        }

        return rob2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max({nums[0], helper(nums, 1, n), helper(nums, 0, n - 1)});
    }
};