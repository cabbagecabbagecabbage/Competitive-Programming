#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

/*
i did not think of bitset

dp[i][j] stores bitset of all possible answers from first i elements, j unmatched start points
either:
	pick to be starting point: dp[i][j] |= dp[i-1][j-1] << (a[i]*a[i])
	pick to be ending point: dp[i][j] |= dp[i-1][j+1] >> (a[i]*a[i])
	dont pick dp[i][j] |= dp[i-1][j]	
*/

const int maxn = 250 + 5, offset = 84735;
int a[maxn];
bitset<offset*2+1> dp[2][maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	for (int i = 1; i <= n; ++i){
		a[i] = s[i-1] - 'A' + 1;
	}
	dp[0][0][offset] = 1;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			if (j > 0) dp[i%2][j] |= (dp[(i-1)%2][j-1] << (a[i]*a[i]));
			if (j != n) dp[i%2][j] |= (dp[(i-1)%2][j+1] >> (a[i]*a[i]));
			dp[i%2][j] |= dp[(i-1)%2][j];
		}
	}
	cout << dp[n%2][0].count() << "\n"; //didnt know this existed
	for (int i = 0; i < offset*2+1; ++i){
		if (dp[n%2][0][i] != 0) cout << i-offset << "\n";
	}
	return 0;
}