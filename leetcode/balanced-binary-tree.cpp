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
    pair<bool, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool balanced =
            left.first && right.first && abs(left.second - right.second) <= 1;

        int height = 1 + max(left.second, right.second);

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) { return dfs(root).first; }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}