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

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* buildTree(vector<int> arr) {
    TreeNode* root = NULL;

    for (int val : arr) {
        root = insert(root, val);
    }

    return root;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}