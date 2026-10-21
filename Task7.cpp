#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

BSTNode* insert(BSTNode* root, int val) {
    if (root == NULL) return new BSTNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(BSTNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    BSTNode* root = NULL;

    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    inorder(root);
    cout << endl;

    return 0;
}