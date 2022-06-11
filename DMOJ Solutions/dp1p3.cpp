#include <bits/stdc++.h>
using namespace std;

int dp[5005], a[5005];

int32_t main(){
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		for (int j = 0; j < i; ++j){
			if (a[j] < a[i]) dp[i] = max(dp[i],dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";	
	return 0;
}