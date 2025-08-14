#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main() {
    
    map<string,int> sheet;
    vector<int> ans;
    
    map<string,int>::iterator itr;
    vector<int>::iterator i;
    
    int Q; cin>>Q;
    
    while(Q>0) {
        
        string name; int type, sum; cin>>type;

            switch (type)
            {
            case 1:
                int mark;
                cin>>name;
                    if(sheet.find(name)!=sheet.end()) {
                        cin>>mark;
                        mark=mark+sheet[name];
                        sheet.erase(name);
                        sheet.insert(make_pair(name,mark));
                    }
                    else {
                        cin>>mark;
                        sheet.insert(make_pair(name,mark));
                    }
                break;
            case 2:
                cin>>name;
                sheet.erase(name);
                break;
            case 3:
                cin>>name;
                itr=sheet.find(name);
                    if(itr!=sheet.end()) {
                        ans.push_back(itr->second);
                    }
                    else {
                        ans.push_back(0);
                    }
                break;
            default:
                break;
            }
        Q--;
    }

    for(i=ans.begin();i!=ans.end();i++) {
        cout<<*i<<endl;
    }

    return 0;
}