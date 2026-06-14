#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long windowSum = 0;
        long long ans = 0;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            windowSum += nums[j];
            freq[nums[j]]++;

            if (j - i + 1 > k) {
                windowSum -= nums[i];

                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);

                i++;
            }

            if (j - i + 1 == k && freq.size() == k) {
                ans = max(ans, windowSum);
            }
        }
        return ans;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}