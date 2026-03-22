#include <iostream>
using namespace std;

int maxSum(int mat[][3], int row, int col)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += mat[i][j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3;
    int col = 3;
    return 0;
}