#include <iostream>
#include <queue>
#include <vector>
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

static int index = -1;
Node* buildTree(vector<int>& preOrder) {
    index++;

    if (preOrder[index] == -1) return NULL;

    Node* root = new Node(preOrder[index]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);

    while (q.size() > 0) {
        Node* curr = q.front();

        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}