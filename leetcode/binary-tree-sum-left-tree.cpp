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
    int total = 0;

    void dfs(TreeNode* node, bool left) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left, true);
        dfs(node->right, false);

        // Current node is a left leaf
        if (node->left == nullptr && node->right == nullptr && left) {
            total += node->val;
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        total = 0;
        dfs(root, false);
        return total;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}