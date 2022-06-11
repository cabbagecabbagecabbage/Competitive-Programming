#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e6 + 5;
int n, t, dp[nax];
vector<int> coins;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		coins.emplace_back(a);
	}
	dp[0] = 1;
	for (int coin: coins){
		for (int i = t; i >= coin; --i){
			dp[i] += dp[i - coin];
		}
	}
	cout << dp[t] << "\n";
	return 0;
}