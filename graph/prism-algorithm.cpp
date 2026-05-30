#include <iostream>
using namespace std;

int prismMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstCost = 0;

    pq.push({0, 0});

    while (pq.size() > 0) {
        int wt = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (!inMST[u]) {
            inMST[u] = true;
            mstCost += wt;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (!inMST[v]) pq.push({w, v});
            }
        }
    }

    return mstCost;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}