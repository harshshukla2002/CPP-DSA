#include <iostream>
#include <set>
using namespace std;

class Solution {
   public:
    int ROWS, COLS;
    set<pair<int, int>> visited;

    int dfs(int r, int c, vector<vector<int>>& grid) {
        // Out of bounds, water, or already visited
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0 ||
            visited.count({r, c})) {
            return 0;
        }

        visited.insert({r, c});

        // Count the current land cell + its neighbors
        return 1 + dfs(r + 1, c, grid) + dfs(r - 1, c, grid) +
               dfs(r, c + 1, grid) + dfs(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                area = max(area, dfs(r, c, grid));
            }
        }

        return area;
    }
};