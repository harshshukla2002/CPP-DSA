#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> res;
    vector<int> cur;

    void backtrack(vector<int>& candidates, int pos, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        if (target < 0) {
            return;
        }

        int prev = -1;

        for (int i = pos; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (candidates[i] == prev) {
                continue;
            }

            cur.push_back(candidates[i]);

            backtrack(candidates, i + 1, target - candidates[i]);

            cur.pop_back();

            prev = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return res;
    }
};