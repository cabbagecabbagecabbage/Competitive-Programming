#include <bits/stdc++.h>
using namespace std;

/*
sort pairs (ai,bi)
dp[i][j] stores the number of ways to choose a subset of the first i pairs whose sum is j (j goes up to max a
base case dp[0][0] = 1
for each pair:
	for j from 0 to max:
		not take pair:
			dp[i][j] += dp[i-1][j]
		take pair:
			dp[i][j] += dp[i-1][j-b[i]]
			
		take pair as maximum:
			if j + b[i] <= a[i] (doesnt exceed):
				ans += dp[i-1][j]

*/

const int nax = 5e3 + 5, mod = 998244353;
int n, dp[nax][nax];
pair<int,int> p[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> p[i].first;
	}
	for (int i = 1; i <= n; ++i){
		cin >> p[i].second;
	}
	sort(p + 1, p + n + 1);
	int ans = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < nax; ++j){
			dp[i][j] = dp[i-1][j];
			if (j >= p[i].second){
				dp[i][j] += dp[i-1][j-p[i].second];
				dp[i][j] %= mod;
			}
			if (j + p[i].second <= p[i].first){
				ans += dp[i-1][j];
				ans %= mod;
			}
			// cout << i << " " << j << " " << dp[i][j] << "\n";
		}
	}
	cout << ans << "\n";
	
	return 0;
}