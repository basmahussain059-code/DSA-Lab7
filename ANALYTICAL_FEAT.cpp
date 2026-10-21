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

int countStudents(Student* root) {
    if (root == NULL) return 0;
    return 1 + countStudents(root->left) + countStudents(root->right);
}

void findMinMaxGPA(Student* root, Student*& minStudent, Student*& maxStudent) {
    if (root == NULL) return;

    if (minStudent == NULL || root->GPA < minStudent->GPA) {
        minStudent = root;
    }
    if (maxStudent == NULL || root->GPA > maxStudent->GPA) {
        maxStudent = root;
    }

    findMinMaxGPA(root->left, minStudent, maxStudent);
    findMinMaxGPA(root->right, minStudent, maxStudent);
}

void displayAboveThreshold(Student* root, float threshold) {
    if (root == NULL) return;

    displayAboveThreshold(root->left, threshold);
    if (root->GPA >= threshold) {
        cout << "ID: " << root->studentID 
             << " | Name: " << root->name 
             << " | GPA: " << root->GPA << endl;
    }
    displayAboveThreshold(root->right, threshold);
}

int main() {
    Student* root = new Student(103, "Ali", 3.4);
    root->left = new Student(101, "Sara", 3.8);
    root->right = new Student(105, "Omar", 2.9);
    root->left->right = new Student(102, "Zain", 3.1);
    root->right->left = new Student(104, "Hina", 3.9);

    cout << "Total Students: " << countStudents(root) << endl << endl;

    Student* minStudent = NULL;
    Student* maxStudent = NULL;
    findMinMaxGPA(root, minStudent, maxStudent);

    if (maxStudent) {
        cout << "Highest GPA: " << maxStudent->name 
             << " (" << maxStudent->GPA << ")" << endl;
    }
    if (minStudent) {
        cout << "Lowest GPA: " << minStudent->name 
             << " (" << minStudent->GPA << ")" << endl;
    }

    cout << "\nStudents with GPA >= 3.5:" << endl;
    displayAboveThreshold(root, 3.5);

    return 0;
}