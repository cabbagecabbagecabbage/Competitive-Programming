#include <bits/stdc++.h>
using namespace std;

int n,k,redcnt[355],dp[355][355][355];
string s;

bool solve(int l, int r, int red){
	int other = redcnt[n-1] - (redcnt[r] - (l == 0 ? 0 : redcnt[l-1])) - red;
	if (red >= k) return dp[l][r][red] = false;
	if (other >= k) return dp[l][r][red] = true;
	if (dp[l][r][red] != -1) return dp[l][r][red];
	return dp[l][r][red] = (
			(!solve(l+1,r,other)) or 
			(!solve(l,r-1,other))
	);
}

int32_t main(){
	memset(dp,-1,sizeof dp);
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; ++i){
		redcnt[i] = s[i] == 'C';
		if (i) redcnt[i] += redcnt[i-1];
	}
	if (solve(0,n-1,0)){
		cout << "DA\n";
	}
	else cout << "NE\n";
	return 0;
}