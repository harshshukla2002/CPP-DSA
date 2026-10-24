#include <iostream>
using namespace std;

class Solution {
   public:
    int binSearch(vector<int>& nums, int target, bool leftBias) {
        int l = 0, r = nums.size() - 1;
        int idx = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (target > nums[m]) {
                l = m + 1;
            } else if (target < nums[m]) {
                r = m - 1;
            } else {
                idx = m;

                if (leftBias) {
                    r = m - 1;  // Search further left
                } else {
                    l = m + 1;  // Search further right
                }
            }
        }

        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binSearch(nums, target, true);
        int right = binSearch(nums, target, false);

        return {left, right};
    }
};