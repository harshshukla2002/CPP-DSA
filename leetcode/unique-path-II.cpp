#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n, 0);
        dp[n - 1] = 1;

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    dp[c] = 0;
                } else if (c + 1 < n) {
                    dp[c] = dp[c] + dp[c + 1];
                }
            }
        }

        return static_cast<int>(dp[0]);
    }
};