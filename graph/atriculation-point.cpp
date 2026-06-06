#include <iostream>
#include <set>
using namespace std;

class Graph {
   public:
    int V;
    vector<vector<int>> adj;

    int time;
    vector<int> dt, low;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addGraph(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parentU, set<int>& criticalPoints) {
        dt[u] = low[u] = ++time;
        int child = 0;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            if (dt[v] == -1) {
                child++;
                dfs(v, u, criticalPoints);
                low[u] = min(low[u], low[v]);

                if (parentU != -1 && low[v] >= dt[u]) {
                    criticalPoints.insert(u);
                }
            } else if (v != parentU) {
                low[u] = min(low[u], dt[v]);
            }
        }

        if (parentU == -1 && child > 1) {
            criticalPoints.insert(u);
        }
    }

    int articulationPoints() {
        time = 0;
        dt.resize(V, -1);
        low.resize(V);

        set<int> criticalPoints;

        for (int i = 0; i < V; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, criticalPoints);
            }
        }

        return criticalPoints.size();
    }
};