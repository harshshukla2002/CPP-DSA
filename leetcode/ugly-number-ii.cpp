#include <iostream>
using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        nums.push_back(1);

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; i++) {
            int next_num = min({nums[i2] * 2, nums[i3] * 3, nums[i5] * 5});

            nums.push_back(next_num);

            if (next_num == nums[i2] * 2) {
                i2++;
            }

            if (next_num == nums[i3] * 3) {
                i3++;
            }

            if (next_num == nums[i5] * 5) {
                i5++;
            }
        }

        return nums[n - 1];
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}