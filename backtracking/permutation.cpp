#include <iostream>
#include <vector>
using namespace std;

void getPermutations(vector<int> &arr, int index, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        res.push_back({arr});
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        getPermutations(arr, index + 1, res);
        swap(arr[index], arr[i]);
    }
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}