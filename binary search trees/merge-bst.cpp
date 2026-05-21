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

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* build(vector<int> arr) {
    TreeNode* root = NULL;

    for (int val : arr) {
        root = insert(root, val);
    }

    return root;
}

void inorder(TreeNode* root, vector<int> arr) {
    if (root == NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

TreeNode* buildBst(vector<int>& arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;

    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildBst(arr, st, mid - 1);
    root->right = buildBst(arr, mid + 1, end);

    return root;
}

TreeNode* merge(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i++]);
        } else {
            temp.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size()) {
        temp.push_back(arr1[i++]);
    }

    while (j < arr2.size()) {
        temp.push_back(arr2[j++]);
    }

    return buildBst(temp, 0, temp.size() - 1);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}