#include <iostream>
#include <vector>
using namespace std;

int subArraySum(vector<int> &arr, int tar)
{
    int n = arr.size();
    int count = 0;
    vector<int> preSum(n, 0);

    preSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        preSum[i] = preSum[i - 1] + arr[i];
    }

    unordered_map<int, int> map;
    for (int j = 0; j < n; j++)
    {
        if (preSum[j] == tar)
            count++;

        int val = preSum[j] - tar;

        if (map.find(val) != map.end())
            count += map[val];

        if (map.find(preSum[j]) == map.end())
        {
            map[preSum[j]] = 1;
        }
        else
        {
            map[preSum[j]]++;
        }
    }

    return count;
}

int main()
{
    cout << "Boiler Plate Code" << endl;
    return 0;
}