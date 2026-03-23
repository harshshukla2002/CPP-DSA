#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> map;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int sec = target - first;

        if (map.find(sec) != map.end())
        {
            ans.push_back(i);
            ans.push_back(map[sec]);
            break;
        }
        map[first] = i;
    }

    return ans;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}