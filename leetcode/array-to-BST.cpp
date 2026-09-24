#include <iostream>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        val = val;
        left = right = NULL;
    }
};

class Solution {
   public:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int m = (l + r) / 2;

        TreeNode* root = new TreeNode(nums[m]);

        root->left = helper(nums, l, m - 1);
        root->right = helper(nums, m + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}