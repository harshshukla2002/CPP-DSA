/*
Question: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*/

#include <iostream>
#include <vector>
using namespace std;

// & => is used to pass value by reference (by default it is pass by value)

// brute force solutions
int singleNumber(vector<int> &num)
{
    int len = num.size();
    int ans;
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        for (int j = 0; j < len; j++)
        {
            if (num[i] == num[j] && i != j)
                count++;
        }
        if (count == 0)
            ans = num[i];
    }

    return ans;
}

// optimised using bitwisexor operator
int singleNumber2(vector<int> &num)
{
    int ans = 0;
    for (int val : num)
    {
        ans ^= val;
    }

    return ans;
}

int main()
{
    vector<int> num = {4, 1, 2, 1, 2};
    cout << singleNumber(num) << endl;
    return 0;
}