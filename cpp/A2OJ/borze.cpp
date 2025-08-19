#include <iostream>
#include <string>

using namespace std;
int main() {
    string borze, ans = "";
    cin >> borze;

    int i = 0;
    while(i < borze.size()) {
        if(borze[i] == '.') {
            ans +='0';
        } else {
            i++;
            if(borze[i] == '.') {
                ans += '1';
            } else {
                ans += '2';
            }
        }
        i++;
    }

    cout<<ans;

    return 0;
}