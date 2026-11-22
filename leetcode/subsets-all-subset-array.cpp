#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        // Decision 1: Include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1, nums);

        // Decision 2: Do NOT include nums[i]
        subset.pop_back();
        dfs(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};