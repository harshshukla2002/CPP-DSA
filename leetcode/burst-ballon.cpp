#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int l, int r) -> int {
            // No balloons left
            if (l > r) {
                return 0;
            }

            // Already calculated
            if (dp[l][r] != -1) {
                return dp[l][r];
            }

            dp[l][r] = 0;

            // Choose the last balloon to burst
            for (int i = l; i <= r; i++) {
                int coins = nums[l - 1] * nums[i] * nums[r + 1];

                coins += dfs(l, i - 1) + dfs(i + 1, r);

                dp[l][r] = max(dp[l][r], coins);
            }

            return dp[l][r];
        };

        return dfs(1, n - 2);
    }
};