#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    bool canSplit(vector<int>& nums, int largest, int m) {
        int subarray = 0;
        long long curSum = 0;

        for (int n : nums) {
            curSum += n;

            if (curSum > largest) {
                subarray++;
                curSum = n;
            }
        }

        return subarray + 1 <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0LL);
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canSplit(nums, mid, m)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};