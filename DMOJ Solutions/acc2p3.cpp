#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

/*
up[node][i] stores the node located 2^i above the current node
best[node][i] stores the {longest, second longest} edges from node to the node located 2^i above the current node
*/

const int nax = 1e5 + 5;
const int logn = ceil(log2(nax));
int n, timer = 0;
int up[nax][logn], tin[nax], tout[nax], depth[nax];
pair<int,int> best[nax][logn];
vector<pair<int,int>> adj[nax];

pair<int,int> merge(pair<int,int> a, pair<int,int> b){
	if (a.first < b.first) swap(a,b);
	return {a.first,max(a.second,b.first)};
}

void dfs(int node, int parent, int prevEdge){
	tin[node] = timer++;
	depth[node] = depth[parent] + 1;
	//process up
	up[node][0] = parent;
	for (int i = 1; i < logn; ++i){
		up[node][i] = up[up[node][i-1]][i-1];
	}
	//process best
	best[node][0] = {prevEdge,-1};
	for (int i = 1; i < logn; ++i){
		best[node][i] = merge(best[node][i-1], best[up[node][i-1]][i-1]);
	}
	//go down
	for (pair<int,int> x: adj[node]){
		if (x.first == parent) continue;
		dfs(x.first, node, x.second);
	}
	tout[node] = timer++;
}

pair<int,int> walkup(int start, int end){
	pair<int,int> ans = {-1,-1};
	int dist = depth[start] - depth[end];
	for (int i = logn - 1; i >= 0; --i){
		if ((1 << i) & dist){
			ans = merge(ans,best[start][i]);
			start = up[start][i];
		}
	}
	return ans;
}

inline bool isAncestor(int u, int v) {return (tin[u] <= tin[v] && tout[u] >= tout[v]);}

int solve(int u, int v){
	int lca;
	if (isAncestor(u,v)) lca = u;
	else if (isAncestor(v,u)) lca = v;
	else {
		lca = u;
		for (int i = logn - 1; i >= 0; --i){
			if (!isAncestor(up[lca][i],v)){
				lca = up[lca][i];
			}
		}
		lca = up[lca][0];
	}
	return merge(walkup(u,lca),walkup(v,lca)).second;
}



int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(best,-1,sizeof(best));
	for (int i = 0; i < nax; ++i) for (int j = 0; j < logn; ++j) up[i][j] = 1;
	cin >> n;
	for (int i = 0; i < n - 1; ++i){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b,w);
		adj[b].emplace_back(a,w);
	}
	dfs(1,1,0);
	int q;
	cin >> q;
	while (q--){
		int u,v;
		cin >> u >> v;
		cout << solve(u,v) << "\n";
	}
	return 0;
}