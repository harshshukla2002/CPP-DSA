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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}