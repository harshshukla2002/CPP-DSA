#include <iostream>
using namespace std;

int time;
vector<int> dt, low;

void dfs(int u, int parentU, vector<vector<int>>& graph, vector<vector<int>>& bridges) {
    dt[u] = low[u] = ++time;

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];

        if (dt[v] == -1) {
            dfs(v, u, graph, bridges);
            low[u] = min(low[u], low[v]);

            // bridge
            if (low[v] > dt[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parentU) {
            low[u] = min(low[u], dt[v]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);

    for (int i = 0; i < connections.size(); i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    time = 0;
    dt.resize(n, -1);
    low.resize(n);

    vector<vector<int>> bridges;

    for (int i = 0; i < n; i++) {
        if (dt[i] == -1) dfs(i, -1, graph, bridges);
    }

    return bridges;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}