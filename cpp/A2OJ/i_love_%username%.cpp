#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int first; cin >> first;

	int m = first, M = first, amazing = 0;
	for(int i = 1; i <= n - 1; i++) {
		int curr; cin >> curr;
		if(curr < m || curr > M) amazing++;
		m = min(m, curr);
		M = max(M, curr);
	}

	cout << amazing;
	
	return 0;
}