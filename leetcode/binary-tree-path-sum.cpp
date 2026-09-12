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
    bool dfs(TreeNode* node, int curSum, int targetSum) {
        if (node == nullptr) {
            return false;
        }

        curSum += node->val;

        // Check only at a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            return curSum == targetSum;
        }

        return dfs(node->left, curSum, targetSum) ||
               dfs(node->right, curSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}