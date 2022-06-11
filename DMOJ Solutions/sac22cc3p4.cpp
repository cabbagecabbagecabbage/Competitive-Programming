#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n,q; cin >> n >> q;
	vector<int> par(n+1),siz(n+1,1),d(n+1),tin(n+1);
	for (int i = 1; i <= n; ++i) par[i] = i;
	vector<pair<int,int>> euler;
	vector<tuple<int,int,int>> qs;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	set<pair<int,int>> dontjoin;
	for (int i = 0; i < q; ++i){
		int op,u,v; cin >> op >> u >> v;
		qs.emplace_back(op,min(u,v),max(u,v));
		if (op == 2) dontjoin.insert({min(u,v),max(u,v)});
	}
	function<int(int)> find = [&](int u){
		return par[u] = u == par[u] ? u : find(par[u]);
	};
	function<void(int,int)> merge = [&](int a, int b){
		a = find(a); b = find(b);
		if (a == b) return;
		if (siz[a] > siz[b]) swap(a,b);
		par[a] = b;
		siz[b] += siz[a];
	};
	for (int u = 1; u <= n; ++u){
		for (int v: adj[u]){
			if (u > v) continue;
			if (!dontjoin.count({u,v})){
				merge(u,v);
			}
		}
	}
	function<void(int,int)> dfs = [&](int u, int p){
		tin[u] = euler.size();
		euler.emplace_back(d[u],u);
		for (int v: adj[u]){
			if (v == p) continue;
			d[v] = d[u] + 1;
			dfs(v,u);
			euler.emplace_back(d[u],u);
		}
	};
	dfs(1,1);
	int len = euler.size();
	vector<pair<int,int>> tree(len*2);
	for (int i = 0; i < len; ++i) tree[len+i] = euler[i];
	for (int i = len - 1; i >= 0; --i) tree[i] = min(tree[i*2],tree[i*2+1]);
	stack<int> ans;
	for (int i = q-1; i >= 0; --i){
		auto [op,u,v] = qs[i];
		if (op == 1){
			if (find(u) != find(v)){
				ans.push(-1);
				continue;
			}
			pair<int,int> lca = {INT_MAX,INT_MAX};
			int l = tin[u], r = tin[v];
			if (l > r) swap(l,r); ++r;
			for (l += len, r += len; l < r; l /= 2, r /= 2){
				if (l%2) lca = min(lca,tree[l++]);
				if (r%2) lca = min(lca,tree[--r]);
			}
			ans.push(d[u] + d[v] - 2*lca.first);
		}
		else {
			merge(u,v);
		}
	}
	while (!ans.empty()){
		cout << ans.top() << "\n";
		ans.pop();
	}
	return 0;
}