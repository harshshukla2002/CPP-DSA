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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        stack<TreeNode*> st;
        stack<bool> visit;

        st.push(root);
        visit.push(false);

        vector<int> res;

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            bool v = visit.top();
            visit.pop();

            if (cur != nullptr) {
                if (v) {
                    // Second time visiting the node
                    res.push_back(cur->val);
                } else {
                    // First time visiting the node

                    // Push current node again
                    st.push(cur);
                    visit.push(true);

                    // Right subtree
                    st.push(cur->right);
                    visit.push(false);

                    // Left subtree
                    st.push(cur->left);
                    visit.push(false);
                }
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}