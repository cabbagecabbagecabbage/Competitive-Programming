#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll n, k, a[105], dp[105][100005];

int32_t main(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	//base case
	dp[0][0] = 1;
	for (int j = 1; j <= k; ++j){
		dp[0][j] = dp[0][j-1];
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= k; ++j){
			//first i children took j candies
			//i-th child takes between 0 and a[i] candies
			//j - 0 = j -> maximum that the first i-1 children took
			//j - a[i] -> minimum that the first i-1 children took
			//then the first i-1 children took between j-a[i] and j candies
			dp[i][j] += dp[i-1][j] - (j-a[i] <= 0 ? 0 : dp[i-1][max(j-a[i],0ll)-1]);
			dp[i][j] %= mod;
			dp[i][j] += dp[i][j-1];
		}
	}
	cout << (dp[n][k] - dp[n][k-1] + mod) % mod << "\n";
	return 0;
}