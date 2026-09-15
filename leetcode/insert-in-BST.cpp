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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Empty position found
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Go right
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        // Go left
        else {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}