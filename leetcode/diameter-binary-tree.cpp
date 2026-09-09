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
    int res = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Diameter passing through current node
        res = max(res, 2 + left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}