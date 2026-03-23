#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findNum(vector<vector<int>> &grid)
{
    unordered_set<int> set;
    vector<int> ans;
    int n = grid.size();

    int a, b;
    int actualSum = 0, expSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            actualSum += grid[i][j];
            if (set.find(grid[i][j]) != set.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }
            set.insert(grid[i][j]);
        }
    }

    expSum = (n * n) * (n * n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}