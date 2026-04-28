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

bool isIdentical(Node* root, Node* subRoot) {
    if (root == NULL || subRoot == NULL) return root == subRoot;

    return root->data == subRoot->data && isIdentical(root->left, root->left) && isIdentical(root->right, root->right);
}

bool isSubtreeOfTree(Node* root, Node* subRoot) {
    if (root == NULL || subRoot == NULL) return root == subRoot;

    if (root->data == subRoot->data && isIdentical(root, subRoot)) {
        return true;
    }

    return isSubtreeOfTree(root->left, subRoot) || isSubtreeOfTree(root->right, subRoot);
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}