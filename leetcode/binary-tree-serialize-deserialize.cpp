#include <functional>
#include <iostream>
#include <sstream>
#include <string>
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

class Codec {
   public:
    // Serialize
    string serialize(TreeNode* root) {
        vector<string> res;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                res.push_back("N");
                return;
            }

            res.push_back(to_string(node->val));

            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        string result;
        for (int i = 0; i < res.size(); i++) {
            if (i > 0)
                result += ",";

            result += res[i];
        }

        return result;
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        vector<string> vals;
        stringstream ss(data);
        string value;

        while (getline(ss, value, ',')) {
            vals.push_back(value);
        }

        int i = 0;

        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            if (vals[i] == "N") {
                i++;
                return nullptr;
            }

            TreeNode* node = new TreeNode(stoi(vals[i]));
            i++;

            node->left = dfs();
            node->right = dfs();

            return node;
        };

        return dfs();
    }
};

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}