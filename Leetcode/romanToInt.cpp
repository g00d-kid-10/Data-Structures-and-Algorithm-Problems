#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    map<char, int> roman;
    map<char, int>::iterator itr;
    int n = s.length();

    roman.insert({'I', 1});
    roman.insert({'V', 5});
    roman.insert({'X', 10});
    roman.insert({'L', 50});
    roman.insert({'C', 100});
    roman.insert({'D', 500});
    roman.insert({'M', 1000});

    int arr[n];

    for(int i=0; i<n; i++) {
        char letter = s[i];
        itr = roman.find(letter);
        arr[i] = itr->second;
    }
    
    // for(int i=0; i<n; i++) {
    //     cout<<arr[i]<<"+"<<endl;
    // }

    int sum = 0;
    for(int i=0; i<n; i++) {
        if((s[i]=='I'||s[i]=='X'||s[i]=='C') && arr[i]<arr[i+1] && i<n-1) {
            sum += arr[i+1] - arr[i];
            i++;
            // cout<<sum<<"*";
        }
        else {
            sum += arr[i];
            // cout<<sum<<"#";
        }
    }
    return sum;
}

int main() {
    cout<<romanToInt("CD");
    return 0;
}