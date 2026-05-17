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

bool search(TreeNode* root, int key) {
    if (root == NULL) return false;

    if (root->val == key) return true;

    if (key < root->val) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}