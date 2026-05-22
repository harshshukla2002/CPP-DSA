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

TreeNode* rightMostInLeftSubtree(TreeNode* root) {
    TreeNode* ans = NULL;

    while (root != NULL) {
        ans = root;
        root = root->right;
    }

    return ans;
}

TreeNode* leftMostInRightSubtree(TreeNode* root) {
    TreeNode* ans = NULL;

    while (root != NULL) {
        ans = root;
        root = root->left;
    }

    return ans;
}

vector<int> getPresSuc(TreeNode* root, int key) {
    TreeNode* curr = root;
    TreeNode* pred = NULL;
    TreeNode* succ = NULL;

    while (curr != NULL) {
        if (key < curr->val) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->val) {
            pred = curr;
            curr = curr->right;
        } else {
            if (curr->left != NULL) {
                pred = rightMostInLeftSubtree(curr->left);
            }

            if (curr->right != NULL) {
                succ = leftMostInRightSubtree(curr->right);
            }

            break;
        }
    }

    return {pred->val, succ->val};
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}