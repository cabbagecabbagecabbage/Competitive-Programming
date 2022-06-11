#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int dp[3], dp2[3];

int32_t main(){
	int n; cin >> n;
	dp[0] = dp[1] = dp[2] = 0; //after 0 days, the happiness is 0
	for (int i = 1; i <= n; ++i){
		int a,b,c; cin >> a >> b >> c;
		dp2[0] = max(dp[1], dp[2]) + a; //choosing activity a on the i-th day
		dp2[1] = max(dp[0], dp[2]) + b; //choosing activity b on the i-th day
		dp2[2] = max(dp[0], dp[1]) + c; //choosing activity c on the i-th day
		dp[0] = dp2[0];
		dp[1] = dp2[1];
		dp[2] = dp2[2];
	}
	cout << max({dp[0],dp[1],dp[2]}) << "\n";
	return 0;
}