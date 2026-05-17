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

TreeNode* getIS(TreeNode* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }

    return root;
}

TreeNode* deleteLogic(TreeNode* root) {
    if (root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    } else {
        TreeNode* IS = getIS(root->right);
        root->val = IS->val;
        root->right - deleteNode(root->right, IS->val);
    }
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        return deleteLogic(root);
    }
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}