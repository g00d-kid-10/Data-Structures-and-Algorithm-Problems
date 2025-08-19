#include <iostream>
using namespace std;

int main() {
	string s1, s2; cin >> s1; cin >> s2;
	int n1 = s1.length(), n2 = s2.length();
	
	string ans = "";
	for(int i = n1 - 1; i >= 0; i--) {
		int a = s1[i] - '0';
		int b = s2[i] - '0';
		int c = a^b;
		ans = (char)('0' + c) + ans;
	}

	cout << ans;

	return 0;
}