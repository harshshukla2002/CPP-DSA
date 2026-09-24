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
    int curSum = 0;

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // Reverse inorder: Right -> Root -> Left
        dfs(node->right);

        int temp = node->val;

        node->val += curSum;

        curSum += temp;

        dfs(node->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        curSum = 0;
        dfs(root);
        return root;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}