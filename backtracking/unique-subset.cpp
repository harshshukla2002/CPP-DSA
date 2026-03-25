#include <iostream>
#include <vector>
using namespace std;

void getAllSubset(vector<int> &arr, vector<int> &ans, vector<vector<int>> &subsets, int i)
{
    if (i == arr.size())
    {
        subsets.push_back(ans);
        return;
    }

    ans.push_back(arr[i]);
    getAllSubset(arr, ans, subsets, i + 1);

    ans.pop_back();

    int index = i + 1;
    while (index < arr.size() && arr[index] == arr[index - 1])
        index++;

    getAllSubset(arr, ans, subsets, index);
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}