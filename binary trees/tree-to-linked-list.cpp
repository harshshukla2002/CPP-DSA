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

TreeNode* nextRight = NULL;

void flatten(TreeNode* root) {
    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}