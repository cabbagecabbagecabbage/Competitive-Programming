#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int d; string x;
	cin >> d >> x;
	for (int i = 0; i < d-1; ++i){
		if (x[i] < x[i+1]){
			swap(x[i],x[i+1]);
			break;
		}
	}
	cout << x << "\n";
	return 0;
}