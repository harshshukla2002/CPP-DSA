#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int res;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        // Ignore negative paths
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        // Maximum path that passes through current node
        res = max(res, root->val + leftMax + rightMax);

        // Return max path going upward (cannot split)
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}