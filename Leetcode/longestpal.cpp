#include <iostream>
using namespace std;

bool isPalin(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        if(s[i] != s[n-1-i]) {
            return 0;
        }
    }
    return 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        for(int i=0; s[i]!='\n'; i++) {
            
        }
    }
};

int main() {
    Solution s;
    s.longestPalindrome("abcdedccde");
}