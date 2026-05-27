#include <iostream>
#include <list>
#include <stack>
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

    void dfs(int curr, vector<bool>& visited, stack<int>& s) {
        visited[curr] = true;

        for (int v : l[curr]) {
            if (!visited[v]) {
                dfs(v, visited, s);
            }
        }

        s.push(curr);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, s);
            }
        }

        while (s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}