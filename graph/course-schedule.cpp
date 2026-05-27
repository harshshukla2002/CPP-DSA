#include <iostream>
using namespace std;

bool isCycleDFS(int curr, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& edges) {
    visited[curr] = true;
    path[curr] = true;

    for (int i = 0; i < edges.size(); i++) {
        int v = edges[i][0];
        int u = edges[i][1];

        if (u == curr) {
            if (!visited[v]) {
                if (isCycleDFS(v, visited, path, edges))
                    return true;
            } else if (path[v])
                return true;
        }
    }

    path[curr] = false;
    return false;
}

bool canFinish(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n, false);
    vector<bool> path(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCycleDFS(i, visited, path, edges)) return false;
        }
    }

    return true;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}