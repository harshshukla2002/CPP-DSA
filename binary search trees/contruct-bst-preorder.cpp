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

TreeNode* logic(vector<int>& preOrder, int& i, int bound) {
    if (i >= preOrder.size() || preOrder[i] > bound) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preOrder[i++]);
    root->left = logic(preOrder, i, root->val);
    root->right = logic(preOrder, i, bound);

    return root;
}

TreeNode* constructBST(vector<int>& preOrder) {
    int i = 0;
    return logic(preOrder, i, INT_MAX);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}