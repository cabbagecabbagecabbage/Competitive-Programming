#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
int n, ans[maxn],p[maxn],sub[maxn];
bool vis[maxn];
vector<int> adj[maxn];

int dfs(int u){
	sub[u] = 1;
	for (int v: adj[u]){
		ans[u] += dfs(v);
		sub[u] += sub[v];
	}
	ans[u] += sub[u];
	// cout << u << " " << sub[u] << " " << ans[u] << "\n";
	return ans[u];
}

int32_t main(){
	cin >> n;
	for (int i = 2; i <= n; ++i){
		cin >> p[i];
		adj[p[i]].emplace_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}