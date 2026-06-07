#include <iostream>
#include <stack>
using namespace std;

class Graph {
   public:
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addGraph(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    void floydWarshall() {
        const int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(V, INF));

        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }

        for (int u = 0; u < V; u++) {
            for (auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = wt;
            }
        }

        // main logic
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};