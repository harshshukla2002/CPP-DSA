#include <iostream>
using namespace std;

class Solution {
   public:
    void kSum(vector<int>& nums, int k, int start, long long target,
              vector<int>& quad, vector<vector<int>>& res) {
        // Not enough elements left
        if (nums.size() - start < k) {
            return;
        }

        // Base case: 2Sum
        if (k == 2) {
            int l = start;
            int r = nums.size() - 1;

            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];

                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    vector<int> temp = quad;

                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);

                    res.push_back(temp);

                    l++;

                    // Skip duplicates
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }

            return;
        }

        // K-Sum
        for (int i = start; i <= (int)nums.size() - k; i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            quad.push_back(nums[i]);

            kSum(
                nums,
                k - 1,
                i + 1,
                target - nums[i],
                quad,
                res);

            quad.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> quad;

        kSum(nums, 4, 0, target, quad, res);

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}