#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
   public:
    stack<TreeNode*> st;

    void storeNodes(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeNodes(root);
    }

    int next() {
        TreeNode* ans = st.top();
        st.pop();

        storeNodes(ans->right);
        return ans->val;
    }

    bool hasNext() {
        return st.size() > 0;
    }
};