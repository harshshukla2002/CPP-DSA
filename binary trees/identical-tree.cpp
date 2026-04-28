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

bool isSame(Node* p, Node* q) {
    if (p == NULL || q == NULL) return p == q;

    bool isLeftSame = isSame(p->left, q->left);
    bool isRightSame = isSame(p->right, q->right);

    return isLeftSame && isRightSame && p->data == q->data;
}

int main() {
    cout << "Boiler Plate Code" << endl;
    return 0;
}