#include <iostream>
using namespace std;

class Edge {
   public:
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this->v = v;
        this->u = u;
        this->wt = wt;
    }

    bool operator<(const Edge& other) const {
        return this->wt < other.wt;
    }
};

class Graph {
   public:
    int V;
    vector<Edge> edges;
    vector<int> parent, rank;

    Graph(int V) {
        this->V = V;

        for (int i = 0; i < V; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    void unionByRank(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB) return;

        if (rank[parentA] == rank[parentB]) {
            parent[parentB] = parentA;
            rank[parentA]++;
        } else if (rank[parentA] > rank[parentB]) {
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void kruskal() {
        sort(edges.begin(), edges.end());
        int mstCost = 0;

        for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];

            int parentU = find(e.u);
            int parentV = find(e.v);

            if (parentU != parentV) {
                unionByRank(e.u, e.v);
                mstCost += e.wt;
            }
        }

        cout << "MST COST: " << mstCost << endl;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}