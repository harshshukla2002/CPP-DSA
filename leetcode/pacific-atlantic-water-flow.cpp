#include <iostream>
using namespace std;

class Solution {
   public:
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited, int prevHeight) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c] ||
            heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        dfs(r + 1, c, heights, visited, heights[r][c]);
        dfs(r - 1, c, heights, visited, heights[r][c]);
        dfs(r, c + 1, heights, visited, heights[r][c]);
        dfs(r, c - 1, heights, visited, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // Pacific: top row and left column
        for (int c = 0; c < COLS; c++) {
            dfs(0, c, heights, pac, heights[0][c]);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, heights, pac, heights[r][0]);
        }

        // Atlantic: bottom row and right column
        for (int c = 0; c < COLS; c++) {
            dfs(ROWS - 1, c, heights, atl, heights[ROWS - 1][c]);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, COLS - 1, heights, atl, heights[r][COLS - 1]);
        }

        vector<vector<int>> res;

        // Cells reachable from both oceans
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};