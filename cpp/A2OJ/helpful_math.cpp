#include <iostream>
using namespace std;

int main() {
	string s; cin >> s;
	
	int n = s.length();
	for(int i = 0; i < n; i += 2) {
		for(int j = 2; j < n; j += 2) {
			if((s[j - 2] - '0') > (s[j] - '0')) swap(s[j - 2], s[j]);
		}
	}

	cout << s;

	return 0;
}