#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> checkPasses(vector<string> passwords, int k) {
    vector<string> answer;
    map<string, int> unique;
    map<string, int>::iterator itr;
    map<string, int>::iterator i;
    int n = passwords.size();
    
    for(int i=0; i<n; i++) {
        if(unique.find(passwords[i])!=unique.end()) {
            itr = unique.find(passwords[i]);
            unique.insert({passwords[i], ++(itr->second)});
        } else {
            unique.insert({passwords[i], 1});
        }

        if(unique.find(passwords[i])->second < k) {
            answer.push_back("ACCEPT");
        } else {
            answer.push_back("REJECT");
        }
    }
    return answer;
}

int main() {
    vector<string> check;
    check = checkPasses({"abc", "ert", "opt", "abc", "opt", "opt", "abc", "syx", "abc"}, 3);
    for(int i=0; i<check.size(); i++) {
        cout<<check[i]<<endl;
    }
    return 0;
}