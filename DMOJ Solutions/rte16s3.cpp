#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 6e3 + 5, logn = log2(6000) + 5;
int n, in[nax], out[nax], timer = 0, depth[nax], up[nax][logn];
vector<pair<int,int>> adj[nax];

void dfs(int u, int p){
	in[u] = timer++;
	up[u][0] = p;
	for (int i = 1; i < logn; ++i) up[u][i] = up[up[u][i-1]][i-1];
	for (pair<int,int> k: adj[u]){
		if (k.first == p) continue;
		depth[k.first] = k.second + depth[u];
		dfs(k.first,u);
	}
	out[u] = timer++;
}

bool isanc(int a, int b){
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b){
	if (isanc(a,b)) return a;
	if (isanc(b,a)) return b;
	for (int i = logn-1; i >= 0; --i){
		if (!isanc(up[a][i],b)) a = up[a][i];
	}
	return up[a][0];
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i){
		int a,b,w; cin >> a >> b >> w;
		adj[a].emplace_back(b,w);
		adj[b].emplace_back(a,w);
	}
	dfs(0,0);
	int q; cin >> q;
	while (q--){
		int a,b; cin >> a >> b;
		cout << depth[a] + depth[b] - 2 * depth[lca(a,b)] << "\n";
	}
	return 0;
}