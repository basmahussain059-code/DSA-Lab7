#include <iostream>
#include <string>
#include <stack>
using namespace std;
//Binary Tree Node representation
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
Node* constructTree(string s) {
    if (s.length() == 0) return NULL;

    stack<Node*> st;
    Node* root = NULL;
    Node* lastCreated = NULL;
    bool isRight = false; 
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            lastCreated = new Node(ch);
            if (root == NULL) {
                root = lastCreated;
            } 
            else if (!st.empty()) {
                Node* parent = st.top();
                if (!isRight) {
                    parent->left = lastCreated;  // Comma se pehle,Left child
                } else {
                    parent->right = lastCreated; // Comma ke baad , Right child
                }
            }
        }
        else if (ch == '(') {
            st.push(lastCreated);
            isRight = false;     
        }
        else if (ch == ',') {
            isRight = true;
        }
        else if (ch == ')') {
            if (!st.empty()) {
                st.pop(); 
            }
        }
    }
    return root;
}
void printTree(Node* root) {
    if (root == NULL) return;

    cout << "Node: [" << root->data << "] -> ";
    if (root->left != NULL) cout << "Left: " << root->left->data << " | ";
    else cout << "Left: NULL | ";

    if (root->right != NULL) cout << "Right: " << root->right->data;
    else cout << "Right: NULL";
    
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}
int main() {
    string treeStr = "a(b(d,e),c(,f(g,)))";

    cout << "Given String: " << treeStr << endl << endl;
    //Construct the tree
    Node* root = constructTree(treeStr);
    //Verify links
    cout << "Tree Links Verification" << endl;
    printTree(root);

    return 0;
}