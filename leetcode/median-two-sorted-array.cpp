#include <iostream>
#include <numeric>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size()) {
            swap(A, B);
        }

        int total = A.size() + B.size();
        int half = total / 2;

        int l = 0, r = A.size();

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int Aleft = (i > 0) ? A[i - 1] : INT_MIN;
            int Aright = (i < A.size()) ? A[i] : INT_MAX;
            int Bleft = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < B.size()) ? B[j] : INT_MAX;

            // Correct partition
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return min(Aright, Bright);
                }

                return (max(Aleft, Bleft) + (double)min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return 0.0;
    }
};