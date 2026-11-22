#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> res;
    vector<int> perm;
    unordered_map<int, int> count;

    void dfs(int n) {
        if (perm.size() == n) {
            res.push_back(perm);
            return;
        }

        for (auto& [num, freq] : count) {
            if (freq > 0) {
                // Choose this number
                perm.push_back(num);
                count[num]--;

                dfs(n);

                // Backtrack
                count[num]++;
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int num : nums) {
            count[num]++;
        }

        dfs(nums.size());

        return res;
    }
};