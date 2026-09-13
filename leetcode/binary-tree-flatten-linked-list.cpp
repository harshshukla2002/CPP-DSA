#include <functional>
#include <iostream>
#include <sstream>
#include <string>
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

class Solution {
   public:
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);

        if (root->left != nullptr) {
            leftTail->right = root->right;

            root->right = root->left;
            root->left = nullptr;
        }

        TreeNode* last;

        if (rightTail != nullptr)
            last = rightTail;
        else if (leftTail != nullptr)
            last = leftTail;
        else
            last = root;

        return last;
    }

    void flatten(TreeNode* root) { dfs(root); }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}