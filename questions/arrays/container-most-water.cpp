/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

#include <iostream>
#include <vector>
using namespace std;

int mostWater(vector<int> &height)
{
    int maxWater = 0;
    int left = 0, right = height.size() - 1;

    while (left < right)
    {
        int w = right - left;
        int ht = min(height[left], height[right]);

        maxWater = max(maxWater, w * ht);

        height[left] < height[right] ? left++ : right--;
    }

    return maxWater;
}

int main()
{
    cout << "Boiler Plate Code" << endl;

    return 0;
}