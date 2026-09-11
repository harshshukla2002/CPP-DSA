#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool dfs(TreeNode* left, TreeNode* right) {
        // Both are NULL
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // One is NULL
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Values must be equal
        if (left->val != right->val) {
            return false;
        }

        // Mirror comparison
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return dfs(root->left, root->right);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}