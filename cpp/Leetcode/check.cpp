#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	stirng p; cin >> p;
	for(char c : p) {
		if(c == 'H' || c == 'Q' || c == '9') {
			cout << "YES";
			break;
		}
	}

	cout << "NO";
	return 0;
}