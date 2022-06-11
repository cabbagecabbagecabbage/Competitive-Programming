#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
knapsack
state: dp[i] stores the maximum gold that can be obtained in i hours
transition:
			dp2[i] stores dp[i-h] + g go backwards
			dp2[i] = max(dp2[i-t] + q) go forwards
			dp[i] = max(dp[i], dp2[i])
*/

const int nax = 5e3 + 5;
int n,H;
int dp[nax], dp2[nax];
bool took[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> H;
	for (int i = 0; i < n; ++i){
		int g,h,q,t;
		cin >> g >> h >> q >> t;
		for (int i = H; i >= 0; --i){
			dp2[i] = (i < h ? 0 : dp[i-h]+g);
			dp[i] = max(dp[i], dp2[i]);
		}
		for (int i = t + h; i <= H; ++i){
			dp2[i] = max(dp2[i], dp2[i-t]+q);
			dp[i] = max(dp[i], dp2[i]);
		}
	}
	cout << dp[H] << "\n";
	
	return 0;
}