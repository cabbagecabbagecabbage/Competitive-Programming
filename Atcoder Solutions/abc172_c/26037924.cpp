#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 2e5 + 5;
int n,m,k,a[nax],b[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i = 1; i <= m; ++i){
		cin >> b[i];
		b[i] += b[i-1];
	}
	int fans = 0;
	for (int i = 0; i <= n; ++i){
		int tk = k - a[i];
		if (tk < 0) break;
		int lo = 1, hi = m, ans = 0;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (b[mid] <= tk){
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		assert(a[i] + b[ans] <= k);
		fans = max(fans, ans + i);
	}
	cout << fans << "\n";
			
	return 0;
}