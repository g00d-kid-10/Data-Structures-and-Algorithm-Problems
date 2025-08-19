#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s1, s2, s3; cin >> s1 >> s2 >> s3;

	vector<int> mp1(26, 0), mp2(26, 0);
	for(char c : s1) mp1[c - 'A']++;

	for(char c : s2) mp1[c - 'A']++;

	for(char c : s3) mp2[c - 'A']++;

	bool conflict = false;				
	for(int i = 0; i < 26; i++) {
		if(mp1[i] != mp2[i]) {
			conflict = true;
			break;
		}
	}

	(!conflict) ? cout << "YES" : cout << "NO";

	return 0;
}