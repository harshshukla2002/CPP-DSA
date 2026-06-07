#include <iostream>
#include <stack>
using namespace std;

class Graph {
   public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addGraph(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void topoSort(int curr, vector<bool>& visited, stack<int>& st) {
        visited[curr] = true;

        for (int neigh : adj[curr]) {
            if (!visited[neigh]) {
                topoSort(neigh, visited, st);
            }
        }

        st.push(curr);
    }

    void dfs(int curr, vector<bool>& visited, vector<vector<int>>& transpose) {
        visited[curr] = true;

        for (int neigh : transpose[curr]) {
            if (!visited[neigh]) {
                dfs(neigh, visited, transpose);
            }
        }
    }

    void kosaraju() {
        // step-1: topo sort
        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, visited, st);
            }
        }

        // step-2: transpose graph
        vector<vector<int>> transpose(V);

        for (int u = 0; u < V; u++) {
            visited[u] = false;
            for (int v : adj[u]) {
                transpose[v].push_back(u);
            }
        }

        // step-3: dfs of transpose
        while (st.size() > 0) {
            int curr = st.top();
            st.pop();

            if (!visited[curr]) {
                dfs(curr, visited, transpose);
            }
        }
    }
};