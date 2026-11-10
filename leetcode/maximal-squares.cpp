#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        map<pair<int, int>, int> cache;

        function<int(int, int)> helper = [&](int r, int c) {
            // Base case
            if (r >= ROWS || c >= COLS) {
                return 0;
            }

            // Return cached result
            if (cache.count({r, c})) {
                return cache[{r, c}];
            }

            int down = helper(r + 1, c);
            int right = helper(r, c + 1);
            int diag = helper(r + 1, c + 1);

            cache[{r, c}] = 0;

            if (matrix[r][c] == '1') {
                cache[{r, c}] = 1 + min({down, right, diag});
            }

            return cache[{r, c}];
        };

        helper(0, 0);

        int maxSide = 0;

        for (auto& [position, side] : cache) {
            maxSide = max(maxSide, side);
        }

        return maxSide * maxSide;
    }
};