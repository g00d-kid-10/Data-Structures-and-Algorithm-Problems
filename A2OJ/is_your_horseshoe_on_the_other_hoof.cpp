#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
	
	unordered_set<int> s;
	s.insert(s1);
	s.insert(s2);
	s.insert(s3);
	s.insert(s4);

	cout << 4 - s.size();

	return 0;
}