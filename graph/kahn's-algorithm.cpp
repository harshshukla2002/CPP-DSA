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

    void topoGraph() {
        vector<int> res;
        vector<int> indeg(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : l[u]) indeg[v]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int v : l[curr]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        for (int val : res) {
            cout << val << " ";
        }

        cout << endl;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}