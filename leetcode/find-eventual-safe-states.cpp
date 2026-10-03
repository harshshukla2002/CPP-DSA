#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    unordered_map<int, bool> safe;

    bool dfs(int i, vector<vector<int>>& graph) {
        // Already calculated
        if (safe.count(i)) {
            return safe[i];
        }

        // Assume unsafe first
        safe[i] = false;

        for (int nei : graph[i]) {
            if (!dfs(nei, graph)) {
                return safe[i];  // false
            }
        }

        // All neighbors are safe
        safe[i] = true;
        return safe[i];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph)) {
                res.push_back(i);
            }
        }

        return res;
    }
};