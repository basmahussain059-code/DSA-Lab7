#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    Node* root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    preorder(root);
    cout << endl;
    return 0;
}