#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // {value, row, index}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minHeap;

        int left = nums[0][0];
        int right = nums[0][0];

        // Put first element of every list into min heap
        for (int i = 0; i < k; i++) {
            int val = nums[i][0];

            left = min(left, val);
            right = max(right, val);

            minHeap.push({val, i, 0});
        }

        vector<int> res = {left, right};

        while (true) {
            auto [val, row, idx] = minHeap.top();
            minHeap.pop();

            // Move to next element in the same list
            idx++;

            // If this list is exhausted, we can no longer
            // have a range containing at least one element
            // from every list.
            if (idx == nums[row].size()) {
                break;
            }

            int nextVal = nums[row][idx];

            minHeap.push({nextVal, row, idx});

            // Current minimum is at the top of heap
            left = get<0>(minHeap.top());

            // Maximum value seen so far
            right = max(right, nextVal);

            // Check whether current range is smaller
            if (right - left < res[1] - res[0]) {
                res = {left, right};
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}