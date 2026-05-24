#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addGraph(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";

            for (int neigh : l[i]) {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal() {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void dfsHelper(int u, vector<bool>& visited) {
        cout << u << " ";

        visited[u] = true;

        for (int v : l[u]) {
            if (!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfsTraversal() {
        int src = 0;
        vector<bool> visited(V, false);

        dfsHelper(src, visited);
    }

    bool isCycleDFS(int src, int par, vector<bool>& visited) {
        visited[src] = true;
        list<int> neigh = l[src];

        for (int v : neigh) {
            if (!visited[v]) {
                if (isCycleDFS(v, src, visited)) return true;
            } else if (v != par)
                return true;
        }

        return false;
    }

    bool isCycleBFS(int src, vector<bool> visited) {
        queue<pair<int, int>> q;

        q.push({src, -1});
        visited[0] = true;

        while (q.size() > 0) {
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            cout << u << " ";

            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                } else if (v != parU) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleDFS(i, -1, visited)) return true;
            }
        }

        return false;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}