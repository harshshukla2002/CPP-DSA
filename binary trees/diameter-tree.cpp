#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int ans = 0;

int height(Node* root) {
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    ans = max(ans, leftHt + rightHt);
    return max(leftHt, rightHt) + 1;
}

int diameterOfTree(Node* root) {
    if (root == NULL) return 0;

    int leftDia = diameterOfTree(root->left);
    int rightDia = diameterOfTree(root->right);
    int currDia = height(root->left) + height(root->right);

    return ans;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}