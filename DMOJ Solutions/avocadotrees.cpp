#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e6 + 5;
int n,q,h,prefix[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q >> h;
	for (int i = 1; i <= n; ++i){
		int a,b; cin >> a >> b;
		prefix[i] = prefix[i-1];
		if (a <= h){
			prefix[i] += b;
		}
	}
	int ans = -1;
	while (q--){
		int l,r; cin >> l >> r;
		ans = max(ans,prefix[r] - prefix[l-1]);
	}
	cout << ans << "\n";
	return 0;
}