#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e5 + 5, inf = 0x3f3f3f3f;
int dpa[nax], dpb[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dpa, 0x3f, sizeof dpa);
	memset(dpb, 0x3f, sizeof dpb);
	dpa[0] = dpb[0] = 0;
	int H,B;
	cin >> H;
	while (H--){
		int a; cin >> a;
		for (int i = nax-1; i >= a; --i){
			if (dpa[i-a] != inf){
				dpa[i] = min(dpa[i], dpa[i-a] + 1);
			}
		}
	}
	cin >> B;
	while (B--){
		int b; cin >> b;
		for (int i = nax-1; i >= b; --i){
			if (dpb[i-b] != inf){
				dpb[i] = min(dpb[i], dpb[i-b] + 1);
			}
		}
	}
	int ans = inf;
	for (int i = 1; i < nax; ++i){
		if (dpa[i] != inf and dpb[i] != inf){
			ans = min(ans, dpa[i] + dpb[i]);
		}
	}
	if (ans != inf) cout << ans << "\n";
	else cout << "impossible" << "\n";
	return 0;
}