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

TreeNode* prev = NULL;

int minimumDistance(TreeNode* root) {
    if (root == NULL) return INT_MAX;

    int ans = INT_MAX;

    if (root->left != NULL) {
        int leftMin = minimumDistance(root->left);
        ans = min(ans, leftMin);
    }

    if (prev != NULL) {
        ans = min(ans, root->val - prev->val);
    }

    prev = root;

    if (root->right != NULL) {
        int rightMin = minimumDistance(root->right);
        ans = min(ans, rightMin);
    }

    return ans;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}