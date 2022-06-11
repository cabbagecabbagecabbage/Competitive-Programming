#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 3e2 + 5;
int a[maxn],b[maxn],dp[maxn][maxn][maxn];

int solve(int idx, int x, int y){
	if (x == 0 and y == 0) return 0;
	if (idx == 0) return 0x3f3f3f3f;
	int& cur = dp[idx][x][y];
	if (cur == -1){
		cur = min(
			solve(idx-1,max(0ll,x-a[idx]),max(0ll,y-b[idx])) + 1,
			solve(idx-1,x,y)
		);
	}
	return cur;
}
	

int32_t main(){
	memset(dp,-1,sizeof dp);
	int n,x,y;
	cin >> n;
	cin >> x >> y;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i];
	}
	int ans = solve(n,x,y);
	cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
	return 0;
}