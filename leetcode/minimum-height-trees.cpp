#include <iostream>
#include <unordered_set>
using namespace std;

#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        // Store degree of each node and initialize leaves
        vector<int> edge_cnt(n, 0);
        queue<int> leaves;

        for (int i = 0; i < n; i++) {
            edge_cnt[i] = adj[i].size();

            if (edge_cnt[i] == 1) {
                leaves.push(i);
            }
        }

        // Remove leaves layer by layer
        while (!leaves.empty()) {
            if (n <= 2) {
                vector<int> result;

                while (!leaves.empty()) {
                    result.push_back(leaves.front());
                    leaves.pop();
                }

                return result;
            }

            int size = leaves.size();

            for (int i = 0; i < size; i++) {
                int node = leaves.front();
                leaves.pop();

                n--;

                for (int neighbor : adj[node]) {
                    edge_cnt[neighbor]--;

                    if (edge_cnt[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        return {};
    }
};