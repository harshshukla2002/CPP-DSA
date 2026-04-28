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

int sumOfNode(Node* root) {
    if (root == NULL) return 0;

    int leftsum = sumOfNode(root->left);
    int rightsum = sumOfNode(root->right);

    return leftsum + rightsum + root->data;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}