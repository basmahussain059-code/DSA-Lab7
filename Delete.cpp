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

Student* findMin(Student* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Student* deleteStudent(Student* root, int id) {
    if (root == NULL) return NULL;

    if (id < root->studentID) {
        root->left = deleteStudent(root->left, id);
    } else if (id > root->studentID) {
        root->right = deleteStudent(root->right, id);
    } else {
        if (root->left == NULL) {
            Student* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Student* temp = root->left;
            delete root;
            return temp;
        }

        Student* temp = findMin(root->right);
        root->studentID = temp->studentID;
        root->name = temp->name;
        root->GPA = temp->GPA;
        root->right = deleteStudent(root->right, temp->studentID);
    }
    return root;
}

void inorder(Student* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->studentID << " ";
    inorder(root->right);
}

int main() {
    Student* root = new Student(103, "Ali", 3.4);
    root->left = new Student(101, "Sara", 3.8);
    root->right = new Student(105, "Omar", 2.9);
    root->left->right = new Student(102, "Zain", 3.1);

    cout << "Before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteStudent(root, 101);

    cout << "After deleting 101: ";
    inorder(root);
    cout << endl;

    return 0;
}