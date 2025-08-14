#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	string s; cin >> s;
	unordered_set<char> unique(s.begin(), s.end());
	int size = unique.size();
	if(size & 1) {
		cout << "IGNORE HIM!";
	} else {
		cout << "CHAT WITH HER!";
	}
	return 0;
}