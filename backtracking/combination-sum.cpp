#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s;

void getCombinations(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &comb)
{
    if (index == arr.size() || target < 0)
        return;

    if (target == 0)
    {
        if (s.find(comb) == s.end())
        {
            ans.push_back({comb});
            s.insert(comb);
        }

        return;
    }

    comb.push_back(arr[index]);
    // single choice
    getCombinations(arr, index + 1, target - arr[index], ans, comb);
    // multiple
    getCombinations(arr, index, target - arr[index], ans, comb);

    comb.pop_back();
    // exclude
    getCombinations(arr, index + 1, target, ans, comb);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> comb;

    getCombinations(arr, 0, target, ans, comb);
    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}