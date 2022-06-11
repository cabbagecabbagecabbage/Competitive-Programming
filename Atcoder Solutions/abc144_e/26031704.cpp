#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 2e5 + 5;
int n,k,a[nax],f[nax];

bool valid(int t){
	int tempk = k;
	for (int i = 0; i < n; ++i){
		int eattime = a[i] * f[i];
		if (eattime > t){
			tempk -= ceil((double) (eattime - t) / f[i]);
		}
	}
	return tempk >= 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; ++i){
		cin >> f[i];
	}
	sort(f,f+n,greater<int>());
	int lo = 0, hi = 1e18, ans = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (valid(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << "\n";
	
	return 0;
}