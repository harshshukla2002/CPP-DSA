#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());

        int l = 0, r = k - 1;

        while (l < r) {
            swap(nums[l++], nums[r--]);
        }

        l = k, r = nums.size() - 1;

        while (l < r) {
            swap(nums[l++], nums[r--]);
        }
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}