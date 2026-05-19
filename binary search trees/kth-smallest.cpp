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

int prevOrder = 0;

int kthSmallest(TreeNode* root, int k) {
    if (root == NULL) {
        return -1;
    }

    if (root->left != NULL) {
        int leftAns = kthSmallest(root->left, k);

        if (leftAns != -1) return leftAns;
    }

    if (prevOrder + 1 == k) return root->val;

    prevOrder += 1;

    if (root->right != NULL) {
        int rightAns = kthSmallest(root->right, k);

        if (rightAns != -1) return rightAns;
    }

    return -1;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}