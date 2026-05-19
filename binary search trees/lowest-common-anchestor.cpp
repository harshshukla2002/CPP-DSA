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

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;

    if (root->val > p->val && root->val > q->val) {
        return LCA(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return LCA(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}