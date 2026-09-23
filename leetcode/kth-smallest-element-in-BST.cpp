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

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            // Go as far left as possible
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            // Process node
            cur = st.top();
            st.pop();

            n++;

            if (n == k) {
                return cur->val;
            }

            // Move to right subtree
            cur = cur->right;
        }

        return -1;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}