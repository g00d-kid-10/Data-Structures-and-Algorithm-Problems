#include <iostream>
using namespace std;

bool prime(int n) {
	if(!n) return false;
	int factors = 0;
	
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) factors++;
	}

	return factors == 2;
}

int main() {
	int n, m; cin >> n >> m;
	while(!prime(++n));
	(n == m) ? cout << "YES" : cout << "NO";
	return 0;
}