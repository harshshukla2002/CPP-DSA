#include <iostream>
using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        // Add all rotten oranges and count fresh oranges
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            // Process oranges that were rotten at the start of this minute
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int row = r + dr;
                    int col = c + dc;

                    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != 1) {
                        continue;
                    }

                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh--;
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}