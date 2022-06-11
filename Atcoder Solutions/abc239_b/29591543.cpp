#include <bits/stdc++.h>
using namespace std;

signed main(){
	long long x; cin >> x;
	cout << x / 10 - (x % 10 < 0) << "\n";
	return 0;
}