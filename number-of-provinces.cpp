#include <iostream>
using namespace std;

void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited) {
    visited[i] = true;

    for (int j = 0; j < isConnected[i].size(); j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(j, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int numOfPro = 0;
    int n = isConnected.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited);
            numOfPro++;
        }
    }

    return numOfPro;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}