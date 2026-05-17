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

bool checkValid(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (root == NULL) return true;

    if (min != NULL && root->val <= min->val) return false;
    if (max != NULL && root->val >= max->val) return false;

    bool fromLeft = checkValid(root->left, min, root);
    bool fromRight = checkValid(root->right, root, max);

    return fromLeft && fromRight;
}

bool isValid(TreeNode* root) {
    return checkValid(root, NULL, NULL);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}