#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[n - 1] = 1;

        // Traverse from bottom-right to top-left
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                // Obstacle: no path through this cell
                if (grid[r][c] == 1) {
                    dp[c] = 0;
                }

                // Add paths from the right cell
                else if (c + 1 < n) {
                    dp[c] = dp[c] + dp[c + 1];
                }
            }
        }

        return dp[0];
    }
};