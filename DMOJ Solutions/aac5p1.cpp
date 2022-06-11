#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int odd = 0, even = 0, n; cin >> n;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		odd += a % 2;
		even += a % 2 == 0;
	}
	cout << odd / 2 + even / 2 << "\n";
	return 0;
}