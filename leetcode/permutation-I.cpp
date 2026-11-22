#include <iostream>
#include <map>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};

        for (int num : nums) {
            vector<vector<int>> newPerms;

            for (auto& p : perms) {
                for (int i = 0; i <= p.size(); i++) {
                    vector<int> pCopy = p;

                    pCopy.insert(pCopy.begin() + i, num);

                    newPerms.push_back(pCopy);
                }
            }

            perms = newPerms;
        }

        return perms;
    }
};