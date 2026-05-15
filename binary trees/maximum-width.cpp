#include <iostream>
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

int maximumWidth(TreeNode* root) {
    queue<pair<TreeNode*, unsigned long long int>> q;

    q.push({root, 0});
    int maxWidth = 0;

    while (q.size() > 0) {
        int currLevelSize = q.size();
        unsigned long long int startIndex = q.front().second;
        unsigned long long int endIndex = q.back().second;

        maxWidth = max(maxWidth, (int)(endIndex - startIndex + 1));

        for (int i = 0; i < currLevelSize; i++) {
            auto curr = q.front();
            q.pop();

            if (curr.first->left) {
                q.push({curr.first->left, curr.second * 2 + 1});
            }

            if (curr.first->right) {
                q.push({curr.first->right, curr.second * 2 + 2});
            }
        }
    }

    return maxWidth;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}