#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int dp[2][10005];
int32_t main(){
	int n,c; cin >> n >> c;
	dp[0][0] = dp[1][0] = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= c; ++j){
			dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j];
			if (j >= i) dp[i%2][j] -= dp[(i-1)%2][j-i];
			dp[i%2][j] %= mod;
		}
	}
	cout << (dp[n%2][c] + mod) % mod;
	return 0;
}