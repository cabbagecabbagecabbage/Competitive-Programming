#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
bs for the smallest m such that sum of all max(0,a[i] - m) (1 <= i <= n) <= k
i.e. if we took the entire next row it would exceed k
now do ans += k * (m-1)
*/

const int nax = 1e5 + 5;
int n,k,a[nax];

bool check(int ub){
	int ridecnt = 0;
	for (int i = 0; i < n; ++i){
		ridecnt += max(0ll, a[i] - ub);
	}
	return ridecnt <= k;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int lo = 0, hi = 2e9, m = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (check(mid)){
			hi = mid - 1;
			m = mid;
		}
		else{
			lo = mid + 1;
		}
	}
	int ans = 0, ridecnt = 0;
	for (int i = 0; i < n; ++i){
		if (a[i] > m){
			ridecnt += a[i] - m;
			ans += (m + 1 + a[i]) * (a[i] - m) / 2;
		}
	}
	ans += (k - ridecnt) * (m);
	cout << ans << "\n";
	return 0;
}