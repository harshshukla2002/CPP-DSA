#include <iostream>
#include <numeric>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> nextDP;

            for (int t : dp) {
                if (t + nums[i] == target) {
                    return true;
                }

                nextDP.insert(t + nums[i]);
                nextDP.insert(t);
            }

            dp = nextDP;
        }

        return dp.count(target) > 0;
    }
};