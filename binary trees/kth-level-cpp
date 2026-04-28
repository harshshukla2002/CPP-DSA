#include <iostream>
#include <queue>
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

void kthLevel(TreeNode* root, int k) {
    if (root == NULL) return;

    if (k == 1) {
        cout << root->val << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}