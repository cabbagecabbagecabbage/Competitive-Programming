#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	vector<int> u(n),v(n),p(n),c(m),f(m);
	for (int i = 0; i < n; ++i) cin >> u[i] >> v[i] >> p[i];
	for (int i = 0; i < m; ++i) cin >> c[i] >> f[i];
	int cap = *max_element(c.begin(),c.end());
	vector<int> dp(cap+1);
	for (int i = 0; i < n; ++i){
		for (int k = 1; u[i]; k *= 2){
			if (k >= u[i]) k = u[i];
			u[i] -= k;
			for (int j = cap; j >= k*v[i]; --j){
				dp[j] = max(dp[j],dp[j-v[i]*k] + p[i]*k);
			}
		}
	}
	int ans = LLONG_MIN;
	for (int i = 0; i < m; ++i){
		ans = max(ans,dp[c[i]] - f[i]);
	}
	cout << ans << "\n";
	return 0;
}