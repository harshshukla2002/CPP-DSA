#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    vector<int> dp;

    int dfs(int i, string& s) {
        // Reached the end: one valid decoding
        if (i == s.size()) {
            return 1;
        }

        // Already calculated
        if (dp[i] != -1) {
            return dp[i];
        }

        // A number cannot start with 0
        if (s[i] == '0') {
            return 0;
        }

        // Decode one digit
        int res = dfs(i + 1, s);

        // Decode two digits if valid (10 to 26)
        if (i + 1 < s.size() &&
            (s[i] == '1' ||
             (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
            res += dfs(i + 2, s);
        }

        return dp[i] = res;
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        return dfs(0, s);
    }
};