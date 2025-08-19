#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string str; cin >> str;
	
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(str[i - 1] == str[i]) ans++;
	}
	
	cout << ans;
	
	return 0;
}