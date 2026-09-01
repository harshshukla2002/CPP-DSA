#include <iostream>
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
    // recursive code
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> res;

        function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if (root == nullptr) {
                return;
            }

            // Left
            inorder(root->left);
            // Root
            res.push_back(root->val);
            // Right
            inorder(root->right);
        };

        inorder(root);

        return res;
    }

    // iterative code
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            // Go as far left as possible
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            // Process the node
            cur = st.top();
            st.pop();

            res.push_back(cur->val);

            // Move to right subtree
            cur = cur->right;
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}