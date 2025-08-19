#include <iostream>
#include <string>

using namespace std;
int main() {
    int n, t; string word;
    
    cin >> n >> t >> word;
    
    for(int i = 0; i < t; i++) {
        for(int j = 1; j < n; j++) {
            if(word[j - 1] == 'B' && word[j] == 'G') {
                swap(word[j - 1], word[j]);
                j++;
            }
        }
    }

    cout<<word;

    return 0;
}