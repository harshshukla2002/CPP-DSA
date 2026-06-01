#include <iostream>
using namespace std;

int manDistance(vector<vector<int>>& points, int point1, int point2) {
    return abs(points[point1][0] - points[point2][0]) + abs(points[point1][1] - points[point2][1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> mstSet(n, false);
    int mstCost = 0;

    pq.push({0, 0});

    while (pq.size() > 0) {
        int wt = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (mstSet[node]) continue;

        mstSet[node] = true;
        mstCost += wt;

        for (int i = 0; i < n; i++) {
            if (!mstSet[i]) {
                int edgeWt = manDistance(points, node, i);
                pq.push({edgeWt, i});
            }
        }
    }

    return mstCost;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}