#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n; cin >> n;
	vector<tuple<int,int,int>> queries;
	vector<int> ans(n+1,-1),d(n+1),tin(n+1),p(n+1),num(n+1);
	vector<vector<int>> adj(n+1);
	vector<pair<int,int>> euler;
	for (int i = 1; i <= n; ++i){
		char op; cin >> op;
		if (op == 'c'){
			int v,w; cin >> v >> w;
			int vnode = num[v], wnode = num[w];
			queries.emplace_back(vnode,wnode,i);
			num[i] = vnode;
		}
		else if (op == 'a'){
			int v; cin >> v;
			int vnode = num[v];
			adj[vnode].emplace_back(i);
			num[i] = i;
			p[i] = vnode;
		}
		else if (op == 'b'){
			int v; cin >> v;
			int vnode = num[v];
			num[i] = p[vnode];
			ans[i] = vnode;
		}
	}
	function<void(int,int)> dfs = [&](int u, int p){
		tin[u] = euler.size();
		euler.emplace_back(d[u],u);
		// cout << u << " " << p << " " << tin[u] << "\n";
		for (int v: adj[u]){
			if (v == p) continue;
			d[v] = d[u] + 1;
			dfs(v,u);
			euler.emplace_back(d[u],u);
		}
	};
	dfs(0,0);
	int len = euler.size();
	vector<pair<int,int>> tree(len*2);
	for (int i = 0; i < len; ++i) tree[i+len] = euler[i];
	for (int i = len-1; i; --i) tree[i] = min(tree[i*2],tree[i*2+1]);
	for (auto [a,b,idx]: queries){
		pair<int,int> res = {INT_MAX,INT_MAX};
		int l = tin[a], r = tin[b];
		if (l > r) swap(l,r);
		// cout << a << " " << b << " " << l << " " << r << "\n";
		++r;
		for (l += len, r += len; l < r; l /= 2, r /= 2){
			if (l%2) res = min(res,tree[l++]);
			if (r%2) res = min(res,tree[--r]);
		}
		ans[idx] = res.first;
		// cout << a << " " << b << " " << res.second << "\n";
	}
	for (int k: ans) if (k != -1) cout << k << "\n";
	return 0;
}