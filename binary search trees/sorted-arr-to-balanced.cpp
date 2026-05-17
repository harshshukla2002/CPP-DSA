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

TreeNode* build(vector<int>& arr, int st, int end) {
    if (st > end) return NULL;

    int mid = st + (end - st) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = build(arr, st, mid - 1);
    root->right = build(arr, mid + 1, end);

    return root;
}

TreeNode* toBalancedBST(vector<int>& arr) {
    return build(arr, 0, arr.size() - 1);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}