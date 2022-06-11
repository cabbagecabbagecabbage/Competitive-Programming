#include <bits/stdc++.h>
using namespace std;
#define int long long
/*

*/

const int nax = 1e5 + 5;
int n,q,arr[nax],diff[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	while (q--){
		int l,r;
		cin >> l >> r;
		diff[l]++;
		diff[r+1]--;
	}
	for (int i = 1; i <= n; ++i){
		diff[i] += diff[i-1];
	}
	sort(diff+1,diff+n+1);
	sort(arr+1,arr+n+1,greater<int>());
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		ans += diff[i] * arr[i];
	}
	cout << ans << "\n";
	
	return 0;
}