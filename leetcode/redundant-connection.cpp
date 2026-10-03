#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> parent;
    vector<int> rank;

    int find(int n) {
        int p = parent[n];

        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        return p;
    }

    bool unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        // Already connected -> this edge creates a cycle
        if (p1 == p2) {
            return false;
        }

        // Union by size
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.assign(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            if (!unite(n1, n2)) {
                return {n1, n2};
            }
        }

        return {};
    }
};