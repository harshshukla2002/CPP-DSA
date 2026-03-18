#include <iostream>
#include <vector>
using namespace std;

void MergeArrays(vector<int> &A, vector<int> &B, int n, int m)
{
    int index = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (A[i] >= B[j])
        {
            A[index--] = A[i--];
        }
        else
        {
            A[index--] = B[j--];
        }
    }

    while (j >= 0)
    {

        A[index--] = B[j--];
    }
}

int main()
{
    vector<int> A = {2, 4, 6};
    vector<int> B = {1, 3, 5};
    int n = 3;
    int m = 3;
    return 0;
}