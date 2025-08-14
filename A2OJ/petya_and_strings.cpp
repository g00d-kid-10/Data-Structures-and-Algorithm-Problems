#include <iostream>
using namespace std;

int cmp(char c1, char c2) {
	if(c1 < 'a') c1 = c1 + ('a' - 'A');
	if(c2 < 'a') c2 = c2 + ('a' - 'A');
	if(c1 == c2) return 0;
	else if(c1 < c2) return -1;
	else return 1;
}

int main() {
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size();
	for(int i = 0; i < n; i++) {
		if(cmp(s1[i], s2[i]) == 0) {
			continue;
		} else if(cmp(s1[i], s2[i]) == -1) {
			cout << "-1"; exit(0);
		} else {
			cout << "1"; exit(0);
		}
	}

	cout << "0";
	
	return 0;
}