#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x = 0, y = 0, z = 0;
	for(int i = 0; i < n; i++) {
		int f1, f2, f3;
		cin >> f1 >> f2 >> f3;
		x += f1; y += f2; z += f3;
	}
	(x == 0 && y == 0 && z == 0) ? cout << "YES" : cout << "NO"; 
	return 0;
}