#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    vector<vector<int>> adj;
    unordered_set<int> visit;

    bool dfs(int node, int prev) {
        // Cycle detected
        if (visit.count(node)) {
            return false;
        }

        visit.insert(node);

        for (int nei : adj[node]) {
            // Don't go back to the parent
            if (nei == prev) {
                continue;
            }

            if (!dfs(nei, node)) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) {
            return true;
        }

        // Build undirected graph
        adj.resize(n);

        for (auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        // Check cycle + connectivity
        return dfs(0, -1) && visit.size() == n;
    }
};