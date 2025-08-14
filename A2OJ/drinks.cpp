#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n; cin >> n;
	
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		sum += x;
	}

	cout << fixed << setprecision(12) << ((double)sum / n);
	
	return 0;
}