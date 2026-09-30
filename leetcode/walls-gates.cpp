#include <iostream>
using namespace std;

class Solution {
   public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ROWS = rooms.size();
        if (ROWS == 0) return;

        int COLS = rooms[0].size();
        queue<pair<int, int>> q;

        // Add all gates to the queue
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int row = r + dr;
                int col = c + dc;

                // Skip out-of-bounds cells and non-empty rooms
                if (row < 0 || row >= ROWS ||
                    col < 0 || col >= COLS ||
                    rooms[row][col] != INT_MAX) {
                    continue;
                }

                rooms[row][col] = rooms[r][c] + 1;
                q.push({row, col});
            }
        }
    }
};