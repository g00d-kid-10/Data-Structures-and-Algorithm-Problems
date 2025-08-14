#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> computeLPSArray(string str) {
        int n = str.length();
        vector<int> lps(n, 0);
        int i=0, j=1;
        while(j<n) {
            if(str[i]==str[j]) {
                i++; lps[j]=i; j++;
            }
            else {
                if(i!=0) {
                    i = lps[i-1];
                }
                else {
                    lps[j]=i;
                    j++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int H = haystack.length();
        int N = needle.length();
        vector<int> lps(N, 0);
        lps = computeLPSArray(needle);
        int i=0, j=0;
        while(i<H && j<N) {
        // cout<<"i:"<<i<<endl;
        // cout<<"j:"<<j<<endl;
            if(haystack[i]==needle[j]) {
                i++, j++;
            }
            else {
                if(j!=0) {
                    j=lps[j-1];
                    // cout<<"Intermidiate j:"<<j<<endl;
                } else {
                    i++;
                }
            }
        }
        // cout<<"i:"<<i<<j<<endl;
        // cout<<"H:"<<H<<endl;
        return (j==N) ? i-j : -1 ;
    }
};

int main() {
    Solution s;
    cout<<s.strStr("a", "a")<<endl;
    cout<<s.strStr("leetcode", "coder")<<endl;
    cout<<s.strStr("coder", "leetcode")<<endl;
    cout<<s.strStr("aaaaa", "aaa")<<endl;
    cout<<s.strStr("bb", "bbbbbbb")<<endl;
    cout<<s.strStr("comeone", "meo")<<endl;
    cout<<s.strStr("butlerjosh", "butler")<<endl;
    return 0;
}