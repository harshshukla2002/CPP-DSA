#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> res;
    vector<int> subset;

    void backtrack(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);
        backtrack(i + 1, nums);
        subset.pop_back();

        // Skip duplicate elements
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Do NOT include nums[i]
        backtrack(i + 1, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrack(0, nums);

        return res;
    }
};