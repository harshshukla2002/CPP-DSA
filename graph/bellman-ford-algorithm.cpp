#include <iostream>
#include <list>
// #include <priority_queue>
using namespace std;

class Edge {
   public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>>& graph, int V) {
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Edge e : graph[u]) {
                if (distance[e.v] > distance[u] + e.wt) {
                    distance[e.v] = distance[u] + e.wt;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}