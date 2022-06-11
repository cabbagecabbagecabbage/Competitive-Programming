#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5;
int n,q,m[nax],v[nax],pre[nax];
vector<int> p[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> m[i];
	}
	for (int i = 1; i <= n; ++i){
		cin >> v[i];
		p[v[i]].emplace_back(i);
	}
	for (int i = 1; i <= n; ++i){
		for (int extorter: p[i]){
			m[extorter] += m[i];
		}
		pre[i] = max(pre[i-1], m[i]);
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		y -= x;
		if (y <= 0 or y > pre[n]){
			cout << -1 << "\n";
		}
		else{
			int lo = 1, hi = n, ans;
			while (lo <= hi){
				int mid = (lo + hi) / 2;
				if (pre[mid] >= y){
					ans = mid;
					hi = mid - 1;
				}
				else lo = mid + 1;
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}