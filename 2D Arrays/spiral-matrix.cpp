#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    int sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top traversal
        for (int j = sCol; j <= eCol; j++)
        {
            ans.push_back(matrix[sRow][j]);
        }

        // right traversal
        for (int i = sRow + 1; i <= eRow; i++)
        {
            ans.push_back(matrix[i][eCol]);
        }

        // botton traversal
        for (int j = eCol - 1; j >= sCol; j--)
        {
            if (sRow == eRow)
                break;
            ans.push_back(matrix[eRow][j]);
        }

        // left traversal
        for (int i = eRow - 1; i >= sRow + 1; i--)
        {
            if (sCol == eCol)
                break;
            ans.push_back(matrix[i][sCol]);
        }

        sRow++, sCol++, eRow--, eCol--;
    }

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}