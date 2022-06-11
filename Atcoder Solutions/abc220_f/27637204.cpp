#include <bits/stdc++.h>
using namespace std;
#define int long long

const int nax = 2e5+5;
int n, sub[nax], dist[nax], a[nax];
vector<int> adj[nax];
int ans = 0;
void dfs(int u, int p){
	sub[u] = 1;
	for (int v: adj[u]){
		if (v == p) continue;
		dist[v] = dist[u] + 1;
		dfs(v,u);
		sub[u] += sub[v];
	}
	ans += dist[u];
}

void dfs2(int u, int p){
	for (int v: adj[u]){
		if (v == p) continue;
		a[v] = a[u] + n - 2*sub[v];
		dfs2(v,u);
	}
}

main(){
	cin >> n;
	for (int i = 0; i < n-1; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1,0);
	a[1] = ans;
	dfs2(1,0);
	for (int i = 1; i <= n; ++i){
		cout << a[i] << "\n";
	}
	return 0;
}