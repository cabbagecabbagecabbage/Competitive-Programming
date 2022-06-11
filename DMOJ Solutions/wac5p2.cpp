#include <bits/stdc++.h>
using namespace std;
#define int long long
/*

*/

const int nax = 2e5 + 5;
int n,q,a[nax],hi[nax],lo[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for (int i = n-1; i >= 0; --i){
		hi[i] = max((i == n-1 ? a[i] : hi[i+1]),a[i]);
		lo[i] = min((i == n-1 ? a[i] : lo[i+1]),a[i]);
		// cout << lo[i] << " " << hi[i] << "\n";
	}
	while (q--){
		int l,e; cin >> l >> e;
		int x = 0, y = n-1, ans = n;
		while (x <= y){
			int m = (x + y) / 2;
			if (abs(hi[m] - l) <= e and abs(lo[m] - l) <= e){
				ans = m;
				y = m - 1;
			}
			else x = m + 1;
		}
		cout << n - ans << "\n";
	}
	
	
	return 0;
}