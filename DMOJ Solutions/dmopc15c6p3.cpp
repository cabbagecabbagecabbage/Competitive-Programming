#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 2e5 + 5;
int n,m,k,diff[nax],p[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	if (k == 0){
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		++diff[a]; --diff[b+1];
	}
	for (int i = 1; i <= n; ++i){
		diff[i] += diff[i-1];
		p[i] = m - diff[i];
	}
	int lp = 1, ans = LLONG_MAX, cursum = 0;
	for (int rp = 1; rp <= n; ++rp){
		cursum += p[rp];
		while (cursum - p[lp] >= k){
			cursum -= p[lp++];
		}
		if (cursum >= k) ans = min(ans, rp - lp + 1);
	}
	cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
	
	return 0;
}