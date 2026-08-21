#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for (int n : nums) {
            n = abs(n);

            // Already negative means we have seen this number
            if (nums[n - 1] < 0) {
                res.push_back(n);
            }

            // Mark as visited
            nums[n - 1] = -nums[n - 1];
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}