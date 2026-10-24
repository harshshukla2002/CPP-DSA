#include <iostream>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            // Left neighbor is greater
            if (m > 0 && nums[m] < nums[m - 1]) {
                r = m - 1;
            }
            // Right neighbor is greater
            else if (m < nums.size() - 1 && nums[m] < nums[m + 1]) {
                l = m + 1;
            }
            // Neither neighbor is greater: peak found
            else {
                return m;
            }
        }

        return -1;
    }
};