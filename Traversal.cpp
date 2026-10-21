#include <iostream>
#include <string>

using namespace std;

struct Student {
    int studentID;
    string name;
    float GPA;
    Student* left;
    Student* right;

    Student(int id, string n, float g) {
        studentID = id;
        name = n;
        GPA = g;
        left = NULL;
        right = NULL;
    }
};

Student* insert(Student* root, int id, string name, float gpa) {
    if (root == NULL) {
        return new Student(id, name, gpa);
    }

    if (id < root->studentID) {
        root->left = insert(root->left, id, name, gpa);
    } else if (id > root->studentID) {
        root->right = insert(root->right, id, name, gpa);
    }

    return root;
}

void inorder(Student* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << "ID: " << root->studentID 
         << " | Name: " << root->name 
         << " | GPA: " << root->GPA << endl;
    inorder(root->right);
}

int main() {
    Student* root = NULL;

    root = insert(root, 105, "Omar", 2.9);
    root = insert(root, 101, "Sara", 3.8);
    root = insert(root, 104, "Hina", 3.9);
    root = insert(root, 102, "Zain", 3.1);
    root = insert(root, 103, "Ali", 3.4);

    inorder(root);

    return 0;
}