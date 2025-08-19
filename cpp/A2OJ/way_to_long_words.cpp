#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int n = s.length();
		if(n > 10) cout << s[0] + to_string(n - 2) + s[n - 1] << '\n';
		else cout << s << '\n';
	}
	return 0;
}