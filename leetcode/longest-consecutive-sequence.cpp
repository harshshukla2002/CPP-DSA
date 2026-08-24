#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;

        for (int n : numSet) {
            // n is the beginning of a sequence
            if (numSet.find(n - 1) == numSet.end()) {
                int length = 1;

                while (numSet.find(n + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}