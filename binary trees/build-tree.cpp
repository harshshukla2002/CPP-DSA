#include <iostream>
#include <vector>
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

int search(vector<int>& inOrder, int left, int right, int target) {
    for (int i = left; i <= right; i++) {
        if (inOrder[i] == target) return i;
    }

    return -1;
}

TreeNode* helper(vector<int>& preOrder, vector<int>& inOrder, int& preIndex, int left, int right) {
    if (left > right) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preOrder[preIndex]);

    int inIndex = search(inOrder, left, right, preOrder[preIndex]);
    preIndex++;

    root->left = helper(preOrder, inOrder, preIndex, left, inIndex - 1);
    root->right = helper(preOrder, inOrder, preIndex, inIndex + 1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
    int preIndex = 0;
    return helper(preOrder, inOrder, preIndex, 0, inOrder.size() - 1);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}