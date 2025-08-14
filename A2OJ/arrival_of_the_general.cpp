#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		v[i] = x;
	}
	
	int M = INT_MIN, m = INT_MAX;
	for(int i = 0; i < n; i++) {
		M = max(M, v[i]);
		m = min(m, v[i]);
	}

	int MI = -1, mi = n;
	for(int i = 0; i < n; i++) {
		if(v[i] == M) {
			MI = i;
			break;
		}
	}

	for(int i = n - 1; i > -1; i--) {
		if(v[i] == m) {
			mi = i;
			break;
		}
	}

	(MI > mi) ? cout << MI + (n - 1 - mi) - 1 : cout << MI + (n - 1 - mi);

	return 0;
}