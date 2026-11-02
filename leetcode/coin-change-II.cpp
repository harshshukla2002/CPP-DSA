#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        const int LIMIT = INT_MAX;

        for (int coin : coins) {
            for (int a = coin; a <= amount; a++) {
                long long ways = (long long)dp[a] + dp[a - coin];

                dp[a] = min(ways, (long long)LIMIT);
            }
        }

        return dp[amount];
    }
};