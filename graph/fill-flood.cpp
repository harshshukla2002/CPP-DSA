#include <iostream>
using namespace std;

void DFS(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newColor || image[i][j] != orgColor) return;

    image[i][j] = newColor;

    DFS(image, i - 1, j, newColor, orgColor);  // top
    DFS(image, i, j + 1, newColor, orgColor);  // right
    DFS(image, i + 1, j, newColor, orgColor);  // bottom
    DFS(image, i, j - 1, newColor, orgColor);  // left
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    DFS(image, sr, sc, color, image[sr][sc]);

    return image;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}