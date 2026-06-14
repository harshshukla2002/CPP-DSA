#include <iostream>
#include <queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> graph[n];

    for (int i = 0; i < flights.size(); i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];

        graph[u].push_back({v, wt});
    }

    queue<pair<int, pair<int, int>>> q;
    vector<int> distance(n, INT_MAX);

    distance[src] = 0;
    q.push({src, {0, -1}});

    while (q.size() > 0) {
        int u = q.front().first;
        int cost = q.front().second.first;
        int stops = q.front().second.second;

        q.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (distance[v] > cost + wt && stops + 1 <= k) {
                distance[v] = cost + wt;
                q.push({v, {distance[v], stops + 1}});
            }
        }
    }

    return distance[dst] == INT_MAX ? -1 : distance[dst];
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}