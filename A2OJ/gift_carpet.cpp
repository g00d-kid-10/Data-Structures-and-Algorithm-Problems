#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int ROW, COL;
        cin >> ROW >> COL;
        vector<vector<char>> carpet(ROW, vector<char>(COL));

        for(int row = 0; row < ROW; row++) {
            for(int col = 0; col < COL; col++) {
                char letter; cin >> letter;
                carpet[row][col] = letter;
            }
        }

        queue<char> name({'v', 'i', 'k', 'a'});
        string ans = "NO";
        
        for(int col = 0; col < COL; col++) {
            char c = name.front();
            
            for(int row = 0; row < ROW; row++) {
                if(carpet[row][col] == c) {
                    name.pop();
                    break;
                }
            }

            if(name.empty()) {
                ans = "YES";
                break;
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}