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

int nodeCounts(Node* root) {
    if (root == NULL) return 0;

    int leftCount = nodeCounts(root->left);
    int rightCount = nodeCounts(root->right);

    return leftCount + rightCount + 1;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}