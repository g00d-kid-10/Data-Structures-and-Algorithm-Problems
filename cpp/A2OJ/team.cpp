#include <iostream>
using namespace std;

int main() {
	int n, count = 0; cin >> n;
	while(n--) {
		int x, y, z; cin >> x >> y >> z;
		if((x & y) || (y & z) || (x & z)) count++;
	}

	cout << count;

	return 0;
}