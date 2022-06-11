#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

*/

const int nax = 1e3 + 5;
int diff[nax];

void solve(){
	int l,n; cin >> l >> n;
	memset(diff, 0, sizeof diff);
	for (int i = 0; i < n; ++i){
		int c,r,d;
		cin >> c >> r >> d;
		diff[max(c-r,1ll)] += d;
		diff[min(c+r,l)+1] -= d;
	}
	for (int i = 1; i <= l; ++i){
		diff[i] += diff[i-1];
	}
	for (int i = 1; i <= l; ++i){
		diff[i] += diff[i-1];
	}
	int m; cin >> m;
	for (int i = 0; i < m; ++i){
		int h; cin >> h;
		int lo = 1, hi = l, ans = 0;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (diff[mid] < h){
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		if (ans == l and diff[l] < h){
			cout << "Bloon leakage" << "\n";
		}
		else cout << ans+1 << "\n";
	}
				
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}