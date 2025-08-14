#include <iostream>
using namespace std;

bool luckyDigit(int digit);
bool luckyNo(int number);
bool nearlyLucky(int number);

bool luckyNo(unsigned long long number) {
	if(!number) return false;
	
	while(number) {
		int rem = number % 10;
		if(!luckyDigit(rem)) return false;
		number /= 10;
	}

	return true;
}

bool luckyDigit(int digit) {
	return digit == 4 || digit == 7;
}


bool nearlyLucky(unsigned long long number) {
	unsigned long long count = 0;
	while(number) {
		int rem = number % 10;
		if(luckyDigit(rem)) {
			count++;	
		}
		number /= 10;
	}
	return luckyNo(count);
}

int main() {
	unsigned long long number; cin >> number;
	if(nearlyLucky(number)) cout << "YES"; else cout << "NO";
	return 0;
}