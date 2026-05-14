#include <iostream>
#include <vector>
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

int sumTree(TreeNode* root) {
    if (root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->val += leftSum + rightSum;

    return root->val;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}