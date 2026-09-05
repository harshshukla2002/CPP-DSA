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

// problem - 987
class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // {column, row, value}
        vector<tuple<int, int, int>> nodes;

        // {node, row, column}
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            nodes.push_back({col, row, node->val});

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        // Sort by:
        // 1. column
        // 2. row
        // 3. value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;

        int prevCol = INT_MIN;

        for (auto [col, row, val] : nodes) {
            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }

            res.back().push_back(val);
        }

        return res;
    }
};

// problem 314
class Solution {
   public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        // {node, column}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        // column -> list of node values
        map<int, vector<int>> cols;

        int minCol = 0;
        int maxCol = 0;

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            // Update column range
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            // Store node value in its column
            cols[col].push_back(node->val);

            // Left child → column - 1
            if (node->left) {
                q.push({node->left, col - 1});
            }

            // Right child → column + 1
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }

        vector<vector<int>> res;

        // Go from leftmost column to rightmost column
        for (int col = minCol; col <= maxCol; col++) {
            res.push_back(cols[col]);
        }

        return res;
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}