#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e4 + 5, mod = 998244353;
string n;
int m,dp[maxn][2][(1 << 10)][2];

int32_t main(){
	cin >> n >> m;
	int reqmask = 0;
	for (int i = 1; i <= m; ++i){
		int c; cin >> c;
		reqmask |= (1 << c);
	}
	
	for (int i = 0; i < n.size(); ++i){
		int dig = n[i] - '0';
		for (int j = 1; j <= (i == 0 ? dig : 9); ++j){
			dp[i+1][j < dig or i > 0][1 << j][0] += 1;
			dp[i+1][j < dig or i > 0][1 << j][1] += j;
			dp[i+1][j < dig or i > 0][1 << j][0] %= mod;
			dp[i+1][j < dig or i > 0][1 << j][1] %= mod;
		}
		for (int free: {0,1}){
			for (int mask = 1; mask < (1 << 10); ++mask){
				for (int j = 0; j <= (free ? 9 : dig); ++j){
					dp[i+1][free or j < dig][mask | (1 << j)][0] += dp[i][free][mask][0];
					dp[i+1][free or j < dig][mask | (1 << j)][1] += dp[i][free][mask][1]*10 + dp[i][free][mask][0]*j;
					dp[i+1][free or j < dig][mask | (1 << j)][0] %= mod;
					dp[i+1][free or j < dig][mask | (1 << j)][1] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i: {0,1}){
		for (int mask = 0; mask < (1 << 10); ++mask){
			if ((mask & reqmask) == reqmask){
				ans = (ans + dp[n.size()][i][mask][1]) % mod;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}