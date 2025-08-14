#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
//#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,n,q;
    string temp;
    vector<string> hrmlcode;
    vector<string> querylist;
    cin>>n>>q;
    cin.ignore(1,'\n');
    
    for(i=0;i<n;i++)
    {
        getline(cin,temp);
        hrmlcode.push_back(temp);
    }

    for(i=0;i<q;i++)
    {
        getline(cin,temp);
        querylist.push_back(temp);
    }

    map<string,string> mapper;
    vector<string> tagstore;
    //vector<string>::iterator itrv;
    //itrv=tagstore.begin();
    string temp1,t,p,v;
    char ch;
    for(i=0;i<n;i++)
    {
        temp=hrmlcode[i];
        temp.erase(remove(temp.begin(),temp.end(),'\"'),temp.end());
        temp.erase(remove(temp.begin(),temp.end(),'>'),temp.end());
        if(temp.substr(0,2)==("</"))
        {
            tagstore.pop_back();
        }
        else
        {
            stringstream tunnel;
            //tunnel.str("");
            tunnel<<temp;
            tunnel>>ch>>t;
            if(tagstore.size()>0)
            {
                temp1=*tagstore.rbegin();
                temp1=temp1+'.'+t;
            }
            else
            {
                temp1=t;
            }

            tagstore.push_back(temp1);
            
            while(tunnel)
            {
                tunnel>>p>>ch>>v;
                mapper[*tagstore.rbegin()+'~'+p]=v;
            }
        }
    }

    for(i=0;i<q;i++)
    {
        if(mapper.find(querylist[i])==mapper.end())
            cout<<"Not Found!"<<endl;
        else
            cout<<mapper[querylist[i]]<<endl;
    }

    
    map<string,string>:: iterator itr;
            for(itr=mapper.begin();itr!=mapper.end();itr++)
            {
                cout<<itr->first<<'\t'<<itr->second<<endl;
            }
    
    return 0;
}