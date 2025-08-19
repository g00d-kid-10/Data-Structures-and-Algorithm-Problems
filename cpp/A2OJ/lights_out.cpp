#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> state(3, vector<int>(3, 1));
	vector<pair<int, int>> dirs = {{0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			while(x--) {
				for(pair<int, int> dir : dirs) {
					int ni = i + dir.first;
					int nj = j + dir.second;
					if(ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
						state[ni][nj] = !state[ni][nj];
					}
				}
			}
		}
	}

	for(auto each : state) {
		for(auto x : each) {
			cout << x;
		}
		cout << endl;
	}
    
    return 0;
}