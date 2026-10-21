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

Student* search(Student* root, int id) {
    if (root == NULL || root->studentID == id) {
        return root;
    }

    if (id < root->studentID) {
        return search(root->left, id);
    }

    return search(root->right, id);
}

int main() {
    Student* root = new Student(103, "Ali", 3.4);
    root->left = new Student(101, "Sara", 3.8);
    root->right = new Student(105, "Omar", 2.9);

    int searchID = 101;
    Student* result = search(root, searchID);

    if (result != NULL) {
        cout << "Student Found:" << endl;
        cout << "ID: " << result->studentID << endl;
        cout << "Name: " << result->name << endl;
        cout << "GPA: " << result->GPA << endl;
    } else {
        cout << "Student with ID " << searchID << " not found." << endl;
    }

    return 0;
}