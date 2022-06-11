#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		long k;
		cin >> k;
		long j=1;
		while (j<=1000){
			if ((long)pow(k+j,3)%1000 == 888){
				cout << k+j << endl;
				j=1001;
			}
			j++;
		}
	}
	return 0;
}