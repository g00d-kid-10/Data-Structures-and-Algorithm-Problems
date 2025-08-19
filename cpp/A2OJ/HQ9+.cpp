#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	string p; cin >> p;
	for(char c : p) {
		if(c == 'H' || c == 'Q' || c == '9') {
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
	return 0;
}