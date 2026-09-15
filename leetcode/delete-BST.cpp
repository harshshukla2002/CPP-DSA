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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Key not found
        if (root == nullptr) {
            return root;
        }

        // Search in right subtree
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Search in left subtree
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Found the node
        else {
            // Case 1: No left child
            if (root->left == nullptr) {
                return root->right;
            }

            // Case 2: No right child
            if (root->right == nullptr) {
                return root->left;
            }

            // Case 3: Two children
            // Find minimum value in right subtree
            TreeNode* cur = root->right;

            while (cur->left != nullptr) {
                cur = cur->left;
            }

            // Replace current value
            root->val = cur->val;

            // Delete duplicate node
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}