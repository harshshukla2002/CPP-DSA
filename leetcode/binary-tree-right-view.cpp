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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int qLen = q.size();
            TreeNode* rightSide = nullptr;

            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node != nullptr) {
                    rightSide = node;

                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if (rightSide != nullptr)
                res.push_back(rightSide->val);
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}