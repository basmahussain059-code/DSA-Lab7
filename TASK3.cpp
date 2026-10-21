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

void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
    Node* root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');

    inorderIterative(root);
    cout << endl;
    return 0;
}