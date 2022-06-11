#include <bits/stdc++.h>
using namespace std;

/*
state
dp[i][a][b] stores the minimum number of boxes chosen from the first i boxes that contain x takoyaki and y taiyaki

transition
solve(i,a,b) = min(solve(i+1,a-x[i],b-y[i])+1,solve(i+1,a,b))

base case
a == 0 and b == 0 ? return 0
i = n ? return inf;
*/

const int nax = 3e2 + 5, inf = 0x3f3f3f3f;
int n,x[nax],y[nax],dp[nax][nax][nax];

int solve(int i, int a, int b){
	if (a <= 0 and b <= 0) return 0;
	if (i == n) return inf;
	int& cur = dp[i][max(a,0)][max(b,0)];
	if (cur != -1) return cur;
	cur = min(solve(i+1,a-x[i],b-y[i]) + 1, solve(i+1,a,b));
	// cout << i << " " << a << " " << b << " " << cur << "\n";
	return cur;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
	}
	memset(dp,-1,sizeof dp);
	int ans = solve(0,a,b);
	cout << (ans == inf ? -1 : ans) << "\n";
	return 0;
}