#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str) {
    int mx = 0;
    for(int i=0; str[i]!='\0'; i++) {
        
        bool v[256] = {0};
        
        for(int j=i; str[j]!='\0'; j++) {
            if(v[str[j]] == 1)
                break;
            else {
                mx = (mx>(j-i+1)) ? mx : (j-i+1);
                v[str[j]] = 1;
            }
        }
    }
    return mx;
}

int main() {
    cout<<longestUniqueSubsttr("godkis");
    return 0;
}