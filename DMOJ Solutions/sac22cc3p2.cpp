#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int m; cin >> m;
	double lo = 0, hi = 1e9;
	while (hi - lo > 1e-7){
		double mid = (lo + hi) / 2;
		if (12*mid*mid - 5 * mid + 1 > m){
			hi = mid;
		}
		else lo = mid;
	}
	cout << fixed << setprecision(10) << (lo + hi) / 2 << "\n";
	return 0;
}