#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    int minimizeArrayValue(vector<int>& nums) {
        long long total = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];

            // Ceiling of total / (i + 1)
            long long avg = (total + i) / (i + 1);

            res = max(res, (int)avg);
        }

        return res;
    }
};