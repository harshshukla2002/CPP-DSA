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

void dijkstra(int src, vector<vector<Edge>>& graph, int V) {
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();

        for (Edge e : graph[u]) {
            if (distance[e.v] > distance[u] + e.wt) {
                distance[e.v] = distance[u] + e.wt;
                pq.push({distance[e.v], e.v});
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