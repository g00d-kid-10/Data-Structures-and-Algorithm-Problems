#include <iostream>
#include <climits>
using namespace std;

int main() {
	int n; cin >> n;
	
	int cap = INT_MIN, each = 0;
	for(int i = 0; i < n; i++) {
		int entry, exit; cin >> exit >> entry;
		each += - exit + entry;
		cap = max(cap, each);
	}

	cout << cap;

	return 0;
}