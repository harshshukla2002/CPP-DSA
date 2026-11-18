#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    vector<vector<int>> dp;

    int dfs(int i, int j, string& s, string& t) {
        // We have matched all characters of t
        if (j == t.size()) {
            return 1;
        }

        // s is exhausted, but t is not
        if (i == s.size()) {
            return 0;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            dp[i][j] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        } else {
            dp[i][j] = dfs(i + 1, j, s, t);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        dp.assign(m, vector<int>(n, -1));

        return dfs(0, 0, s, t);
    }
};