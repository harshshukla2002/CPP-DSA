#include <iostream>
#include <set>
using namespace std;

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();

        // min-heap: {time/maxHeight, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minH;

        set<pair<int, int>> visit;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        minH.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while (!minH.empty()) {
            auto [t, r, c] = minH.top();
            minH.pop();

            // Reached bottom-right
            if (r == N - 1 && c == N - 1) {
                return t;
            }

            for (auto [dr, dc] : directions) {
                int neiR = r + dr;
                int neiC = c + dc;

                // Out of bounds or already visited
                if (neiR < 0 || neiC < 0 || neiR >= N || neiC >= N ||
                    visit.count({neiR, neiC})) {
                    continue;
                }

                visit.insert({neiR, neiC});

                int newTime = max(t, grid[neiR][neiC]);

                minH.push({newTime, neiR, neiC});
            }
        }

        return -1;
    }
};