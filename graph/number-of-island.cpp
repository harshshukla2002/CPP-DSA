#include <iostream>
using namespace std;

void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') return;

    visited[i][j] = true;

    dfs(i - 1, j, visited, grid, n, m);  // top
    dfs(i, j + 1, visited, grid, n, m);  // right
    dfs(i + 1, j, visited, grid, n, m);  // bottom
    dfs(i, j - 1, visited, grid, n, m);  // left
}

int numOfIsland(vector<vector<char>>& grid) {
    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                dfs(i, j, visited, grid, n, m);
                islands++;
            }
        }
    }

    return islands;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}