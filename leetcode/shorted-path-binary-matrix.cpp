#include <iostream>
using namespace std;

class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Start or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // {row, col, path length}
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        // 8 possible directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        while (!q.empty()) {
            auto [r, c, length] = q.front();
            q.pop();

            // Destination reached
            if (r == n - 1 && c == n - 1) {
                return length;
            }

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Check boundaries, obstacles, and visited cells
                if (nr < 0 || nr >= n || nc < 0 || nc >= n ||
                    grid[nr][nc] == 1 || visited[nr][nc]) {
                    continue;
                }

                visited[nr][nc] = true;
                q.push({nr, nc, length + 1});
            }
        }

        return -1;
    }
};