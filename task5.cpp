#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool validateTreeString(string s) {
    int openCount = 0;
    stack<int> commaStack;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(') {
            openCount++;
            commaStack.push(0);
        } else if (ch == ',') {
            if (commaStack.empty()) return false;
            commaStack.top()++;
            if (commaStack.top() > 1) {
                return false;
            }
        } else if (ch == ')') {
            openCount--;
            if (openCount < 0) return false;
            if (!commaStack.empty()) {
                commaStack.pop();
            }
        }
    }
    return (openCount == 0);
}

int main() {
    string s = "a(b(d,e),c(,f(g,)))";
    if (validateTreeString(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}