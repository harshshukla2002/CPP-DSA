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

// using recursion
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// BFS approach
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            level++;
        }

        return level;
    }
};

// DFS approach
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int res = 0;

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            if (node != nullptr) {
                res = max(res, depth);

                st.push({node->left, depth + 1});
                st.push({node->right, depth + 1});
            }
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}