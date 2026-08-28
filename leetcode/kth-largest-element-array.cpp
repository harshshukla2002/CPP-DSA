#include <iostream>
#include <list>
using namespace std;

class Solution {
   public:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[l];
        }

        int pivot = nums[l];

        int low = l;
        int mid = l;
        int high = r;

        // 3-way partition
        while (mid <= high) {
            if (nums[mid] < pivot) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] > pivot) {
                swap(nums[mid], nums[high]);
                high--;
            } else {
                mid++;
            }
        }

        // [l ... low-1]     < pivot
        // [low ... high]    == pivot
        // [high+1 ... r]    > pivot

        if (k < low) {
            return quickSelect(nums, l, low - 1, k);
        } else if (k > high) {
            return quickSelect(nums, high + 1, r, k);
        } else {
            return nums[k];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // kth largest = (n-k)th smallest
        int target = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}