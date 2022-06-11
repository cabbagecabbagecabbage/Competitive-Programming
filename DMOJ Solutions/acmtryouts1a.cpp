#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		string k;
		cin >> k;
		if (k=="Scissors"){
			cout << "Rock" << endl;
		}
		if (k=="Rock"){
			cout << "Paper" << endl;
		}
		if (k=="Paper"){
			cout << "Scissors" << endl;
		}
		if (k=="Fox"){
			cout << "Foxen" << endl;
		}
		if (k=="Foxen"){
			return 0;
		}
	}
	return 0;
}