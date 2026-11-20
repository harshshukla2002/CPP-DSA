#include <iostream>
#include <map>
#include <numeric>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> arr(n, 1);

        // Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                arr[i] = max(arr[i], arr[i + 1] + 1);
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};