#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency
        unordered_map<int, int> count;
        for (int n : nums) { count[n]++; }

        // Bucket: index = frequency
        vector<vector<int>> freq(nums.size() + 1);
        for (auto& [n, c] : count) { freq[c].push_back(n); }

        // Traverse from highest frequency to lowest
        vector<int> res;

        for (int i = freq.size() - 1; i >= 1; i--) {
            for (int n : freq[i]) {
                res.push_back(n);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}