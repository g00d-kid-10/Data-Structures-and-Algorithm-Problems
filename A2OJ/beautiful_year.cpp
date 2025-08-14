#include <iostream>
using namespace std;

bool isBeauty(int x) {
    string str = to_string(x);
    int n = str.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(str[i] == str[j]) return false;
        }
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    while(!isBeauty(++x)) {}
    cout << x;
    return 0;
}