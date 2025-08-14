#include <iostream>
#include <string>
using namespace std;


bool upper(char c) {
	return 65 <= c && c <= 90;
}

bool lower(char c) {
	return 97 <= c && c <= 122;
}

int main() {
	string str;
	cin >> str;
	
	int u = 0, l = 0;
	for(char c : str) {
		if(upper(c)) u++;
		if(lower(c)) l++;
	}

	if(l >= u) {
		for(int i = 0; i < str.length(); i++) {
			if(upper(str[i])) str[i] = str[i] + 32;
		}
	} else {
		for(int i = 0; i < str.length(); i++) {
			if(lower(str[i])) str[i] = str[i] - 32;
		}
	}

	cout << str;

	return 0;
}