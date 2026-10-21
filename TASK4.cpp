#include <iostream>
#include <stack>

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

void postorderIterative(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != NULL)  s1.push(curr->left);
        if (curr->right != NULL) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    Node* root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');

    postorderIterative(root);
    cout << endl;
    return 0;
}