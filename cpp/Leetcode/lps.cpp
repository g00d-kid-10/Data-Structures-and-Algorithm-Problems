#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPSArray(string& pat) {
    int n = pat.length();
    vector<int> lps(n, 0);
    int i=0,j=1;
    while(pat[j]<n) {
        if(pat[i]==pat[j]) {
            i++;
            lps[j]=i;
            j++;
        }
        else {
            if(i!=0) {
                i=lps[i-1];
            }
            else {
                lps[j]=i;
                j++;
            }
        }
    }
    return lps;
}

int main() {
    string str = "aacaaaac";
    vector<int> v;
    int n = str.length();
    v = computeLPSArray(str);
    for(int i=0; i<n; i++) {
        cout<<v[i];
    }
    
    return 0;
}