#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n,k; cin >> n >> k;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	int ans = 0;
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	int diff = abs(a[0] - b[0]);
	if (diff >= k){
		//add to smaller guy
		if (a[0] < b[0]) a[0] += k;
		else b[0] += k;
	}
	else {
		//apply evenly
		k -= diff;
		a[0] = b[0] = max(a[0],b[0]);
		a[0] += floor((double) k / 2);
		b[0] += ceil((double) k / 2);
	}
	int mod = 1e9 + 7;
	for (int i = 0; i < n; ++i){
		ans += a[i] * b[i];
		ans %= mod;
	}
	cout << ans << "\n";
	return 0;
}