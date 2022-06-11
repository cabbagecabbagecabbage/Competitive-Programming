#include <bits/stdc++.h>
using namespace std;

int main() {
	string letters = "IOSHZXN";
	string input;
	cin >> input;
	for (char a: input){
		bool allowed = false;
		for (char b: letters){
			if (a == b){
				allowed = true;
			}
		}
		if (!allowed){
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";	
	return 0;
}