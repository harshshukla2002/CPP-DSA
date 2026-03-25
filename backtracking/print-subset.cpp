#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &arr, vector<int> &subset, int i)
{
    if (i == arr.size() - 1)
        return;

    subset.push_back(arr[i]);
    printSubset(arr, subset, i + 1);

    // exclude - backtracking
    subset.pop_back();
    printSubset(arr, subset, i + 1);
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}