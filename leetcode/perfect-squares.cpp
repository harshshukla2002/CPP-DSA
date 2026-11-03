#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int target = 1; target <= n; target++) {
            for (int s = 1; s * s <= target; s++) {
                int square = s * s;

                dp[target] = min(dp[target], 1 + dp[target - square]);
            }
        }

        return dp[n];
    }
};