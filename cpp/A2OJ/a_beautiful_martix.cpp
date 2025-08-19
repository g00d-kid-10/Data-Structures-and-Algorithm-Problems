#include <iostream>
using namespace std;
int main() {
    int n, x, y;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> n;
            if(n == 1) {
                x = i; y = j;
                break;
            }
        }
    }
    cout<<abs(2-x)+abs(2-y);
    return 0;
}