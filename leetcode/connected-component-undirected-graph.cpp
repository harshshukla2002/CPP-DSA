#include <iostream>
using namespace std;

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> rank(n, 1);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Find the root with path compression
        auto find = [&](int x) {
            while (x != par[x]) {
                par[x] = par[par[x]];
                x = par[x];
            }
            return x;
        };

        // Union two components
        auto unite = [&](int n1, int n2) {
            int p1 = find(n1);
            int p2 = find(n2);

            // Already in the same component
            if (p1 == p2) {
                return 0;
            }

            // Attach the smaller component to the larger one
            if (rank[p2] > rank[p1]) {
                par[p1] = p2;
                rank[p2] += rank[p1];
            } else {
                par[p2] = p1;
                rank[p1] += rank[p2];
            }

            return 1;
        };

        int res = n;

        for (auto& edge : edges) {
            res -= unite(edge[0], edge[1]);
        }

        return res;
    }
};