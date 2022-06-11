#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
total paths - no 3 nodes same colour

at most 4 nodes long

root tree at 1

dp[u][i][j] number of paths going down from u, i black j white

if u is black:
	dp[1][0] = 1
	dp[u][i][j] = sum over dp[v][i-1][j] for all children v
symmetric for v

path can go thru a node
loop thru i j values of children i guess
*/

int32_t main(){
	int n; cin >> n;
	string s; cin >> s;
	vector<vector<int>> adj(n+1);
	vector<vector<vector<int>>> dp(n+1,{{0,0,0},{0,0,0},{0,0,0}});
	vector<bool> col(n+1);
	for (int i = 1; i <= n; ++i) col[i] = s[i-1] == 'B';
	for (int i = 1; i < n; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	int ans = n * (n-1) / 2 + n;
	function<void(int,int)> dfs = [&](int u, int p){
		//calculate dp vals
		if (col[u]) dp[u][1][0] = 1;
		else dp[u][0][1] = 1;
		for (int v: adj[u]){
			if (v == p) continue;
			dfs(v,u);
			for (int i = 0; i <= 2; ++i){
				for (int j = 0; j <= 2; ++j){
					if (col[u]){
						if (i != 0) dp[u][i][j] += dp[v][i-1][j];
					}			
					if (!col[u]){
						if (j != 0) dp[u][i][j] += dp[v][i][j-1];
					}
				}
			}
		}
		//subtract paths going down from node
		for (int i = 0; i <= 2; ++i)
			for (int j = 0; j <= 2; ++j){
				// if (dp[u][i][j] != 0) cout << u << " " << i << " " << j << " " << dp[u][i][j] << "\n";
				ans -= dp[u][i][j];
			}
		//subtract paths going thru node
		int tot = 0;
		for (int v: adj[u]){
			if (v == p) continue;
			for (int i: {0,1,2}){
				for (int j: {0,1,2}){
					for (int k: {0,1,2}){
						for (int l: {0,1,2}){
							if (k + l <= 1) continue;
							int tmp = dp[u][k][l];
							if (col[u]){
								if (k != 0) tmp -= dp[v][k-1][l];
							}
							else {
								if (l != 0) tmp -= dp[v][k][l-1];
							}
							if (tmp <= 0 or dp[v][i][j] <= 0) continue;
							if (i + k < 3 and j + l < 3){
								// cout << u << " " << k << " " << l << "\n";
								// cout << v << " " << i << " " << j << "\n";
								// cout << dp[v][i][j] << " " << dp[u][k][l] << " " << tmp << "\n\n";
								tot += dp[v][i][j] * tmp;
							}
						}
					}
				}
			}
		}
		ans -= tot / 2;
	};
	dfs(1,1);
	// assert(ans >= 0);
	cout << ans << "\n";					
	return 0;
}