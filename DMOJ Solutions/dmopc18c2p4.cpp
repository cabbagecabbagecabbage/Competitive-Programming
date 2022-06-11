#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 5e5 + 5;
int n,s,a[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int lp = 0, cursum = 0, ans = INT_MAX;
	for (int rp = 0; rp < n; ++rp){
		cursum += a[rp];
		while (cursum - a[lp] >= s){
			cursum -= a[lp++];
		}
		if (cursum >= s) ans = min(ans, rp - lp + 1);
	}
	cout << (ans == INT_MAX ? -1 : ans) << "\n";
	
	return 0;
}