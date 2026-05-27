#include <iostream>
#include <list>
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

    bool isCycleHelper(int curr, vector<bool>& visited, vector<bool>& path) {
        visited[curr] = true;
        path[curr] = true;

        for (int v : l[curr]) {
            if (!visited[v]) {
                if (isCycleHelper(v, visited, path))
                    return true;

            } else if (path[v])
                return true;
        }

        path[curr] = false;
        return false;
    }

    bool isCycle() {
        vector<bool> visited(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleHelper(i, visited, path)) return true;
            }
        }

        return false;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}