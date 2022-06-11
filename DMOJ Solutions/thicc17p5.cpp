#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5;
int n,k,a[nax];
int freq[(int) (1e6+5)];


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int lp = 0, diff = 0, ans = n * (n-1) / 2 + n;
	for (int rp = 0; rp < n; ++rp){
		if (++freq[a[rp]] == 1) ++diff;
		while (diff >= k){
			if (--freq[a[lp++]] == 0) --diff;
		}
		ans -= rp - lp + 1;
	}
	cout << ans << "\n";
	
	return 0;
}