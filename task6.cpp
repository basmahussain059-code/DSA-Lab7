#include <iostream>
#include <algorithm>

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

int getHeight(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

void printDepths(Node* root, int depth) {
    if (root == NULL) return;

    cout << "Node: " << root->data << " -> Depth: " << depth << endl;
    printDepths(root->left, depth + 1);
    printDepths(root->right, depth + 1);
}

int main() {
    Node* root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');

    cout << "Height: " << getHeight(root) << endl;
    printDepths(root, 0);

    return 0;
}