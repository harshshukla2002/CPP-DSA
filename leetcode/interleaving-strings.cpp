#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        // Length check
        if (m + n != s3.size()) {
            return false;
        }

        // DP table
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case
        dp[m][n] = true;

        // Fill from bottom-right to top-left
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }

                if (j < n && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};