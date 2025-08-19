#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int temp = strs[0].length();
        int size = strs.size();
        for(int i=0; i<size; i++) {
            int n = strs[i].length();
            temp = (n<temp) ? n : temp;
        }

        for(int i=0; i<temp; i++) {
            int j=0;
            char a='\0', b='\0', charmatch=strs[j].at(i);
            while(j<size-1) {
                a = strs[j].at(i);
                    j++;
                b = strs[j].at(i);
                if(a!=b) {
                    return ans;
                }
                else {
                    charmatch = a;
                }
            }
            ans+=charmatch;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> que = {"famtonite", "family", "fame"};
    cout<<s.longestCommonPrefix(que);
    return 0;
}