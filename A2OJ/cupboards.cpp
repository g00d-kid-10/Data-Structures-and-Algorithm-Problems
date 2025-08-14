#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;

	int lc = 0, rc = 0;
	for(int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		if(l) lc++;
		if(r) rc++;
	}

	int lreq = 0, rreq = 0;
	if(lc > n/2) lreq = n - lc; else lreq = lc;
	if(rc > n/2) rreq = n - rc; else rreq = rc;

	cout << lreq + rreq;

	return 0;
}