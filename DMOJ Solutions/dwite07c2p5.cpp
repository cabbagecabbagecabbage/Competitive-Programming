#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n,m,lvl[maxn],dp[maxn];
vector<int> adj[maxn];

void dfs(int u){
	for (int v: adj[u]){
		if (lvl[v] == 0){
			//unvisited
			lvl[v] = lvl[u] + 1;
			dfs(v);
			dp[u] += dp[v];
		}
		else if (lvl[v] < lvl[u]){
			//visited before u: back edge over uv
			++dp[u];
		}
		else if (lvl[v] > lvl[u]){
			//visited through a sibling: back edge ends at u
			--dp[u];
		}
	}
	//one of them went back to parent
	--dp[u];
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	lvl[1] = 1;
	dfs(1);
	int ans = 0;
	for (int i = 2; i <= n; ++i){
		ans += dp[i] == 0;
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; ++i){
		adj[i].clear();
		lvl[i] = 0;
		dp[i] = 0;
	}
}

int32_t main(){
	cin.sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; ++i) solve();
	return 0;
}