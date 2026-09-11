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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are NULL
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // One is NULL or values are different
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        // Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}