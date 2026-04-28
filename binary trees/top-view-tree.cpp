#include <iostream>
#include <map>
#include <queue>
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

void topView(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (q.size() > 0) {
        TreeNode* curr = q.front().first;
        int currHd = q.front().second;

        q.pop();

        if (mp.find(currHd) == mp.end()) {
            mp[currHd] = curr->val;
        }

        if (curr->left != NULL) q.push({curr->left, currHd - 1});
        if (curr->right != NULL) q.push({curr->right, currHd + 1});
    }

    for (auto it : mp) {
        cout << it.second << " ";
    }

    cout << endl;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}