#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char a, char b) {
    return a=='{' && b=='}' || a=='[' && b==']' || a=='(' && b==')';
}

bool isOpen(char a) {
    return a=='{' || a=='[' || a=='(';
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        for(int i=0; s[i]!='\0'; i++) {
            if(isOpen(s[i])) {
                container.push(s[i]);
            } else {
                if(!container.empty() && isMatch(container.top(), s[i])) {
                    container.pop();
                } else {
                    return false;
                }
            }
        }
        return container.empty() == 1;
    }
};

int main() {
    Solution sol;
    cout<<sol.isValid("(){}}{");
    return 0;
}


