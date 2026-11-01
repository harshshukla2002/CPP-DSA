#include <iostream>
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // Returns {withRoot, withoutRoot}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> leftPair = dfs(root->left);
        pair<int, int> rightPair = dfs(root->right);

        // Rob the current node: cannot rob its children
        int withRoot = root->val + leftPair.second + rightPair.second;

        // Skip the current node: children can be robbed or skipped
        int withoutRoot = max(leftPair.first, leftPair.second) +
                          max(rightPair.first, rightPair.second);

        return {withRoot, withoutRoot};
    }

    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};