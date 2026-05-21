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

class Info {
   public:
    int min, max, size;

    Info(int mi, int ma, int sz) {
        min = mi;
        max = ma;
        size = sz;
    }
};

Info helper(TreeNode* root) {
    if (root == NULL) return Info(INT_MAX, INT_MIN, 0);

    Info left = helper(root->left);
    Info right = helper(root->right);

    if (root->val > left.max && root->val < right.min) {
        int currMin = min(root->val, left.min);
        int currMax = max(root->val, right.max);
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBst(TreeNode* root) {
    Info info = helper(root);
    return info.size;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}