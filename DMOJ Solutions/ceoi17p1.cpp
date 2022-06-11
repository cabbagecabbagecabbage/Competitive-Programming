#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1), adj2(n+1);
	vector<pair<int,int>> edges;
	for (int i = 1; i <= m; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b,i);
		adj[b].emplace_back(a,-i);
	}
	vector<int> dp(n+1),lvl(n+1),par(n+1),siz(n+1,1);
	vector<char> ans(m+1,'?');
	//dsu
	for (int i = 1; i <= n; ++i) par[i] = i;
	function<int(int)> find = [&](int u){
		return par[u] = par[u] == u ? u : find(par[u]);
	};
	function<void(int,int)> merge = [&](int a, int b){
		a = find(a), b = find(b);
		if (a == b) return;
		if (siz[a] > siz[b]) swap(a,b);
		par[a] = b;
		siz[b] += siz[a];
	};
	vector<tuple<int,int,int>> bridges;
	vector<bool> vis(n+1);
	//bridge finding dfs tree
	function<void(int)> dfs = [&](int u){
		vis[u] = true;
		for (auto[v,idx]: adj[u]){
			if (lvl[v] == 0){
				lvl[v] = lvl[u] + 1;
				dfs(v);
				if (dp[v] != 0){
					merge(u,v); //if not bridge, merge
					ans[abs(idx)] = 'B';
				}
				else {
					bridges.emplace_back(u,v,idx);
				}
				dp[u] += dp[v];
			}
			else if (lvl[v] < lvl[u]) ++dp[u];
			else if (lvl[v] > lvl[u]) --dp[u];
		}
		--dp[u];
	};
	for (int i = 1; i <= n; ++i) if (!vis[i]) lvl[i] = 1,dfs(i);

	for (auto [u,v,idx]: bridges){
		int pu = find(u), pv = find(v);
		adj2[pu].emplace_back(pv,idx);
		adj2[pv].emplace_back(pu,-idx);
	}
	
	vector<int> tin(n+1),ip(n+1),d(n+1),pa(n+1),vis2(n+1);
	vector<pair<int,int>> euler;
	//dfs for parent edge index, tin, euler tour, depth
	function<void(int,int)> dfs2 = [&](int u, int p){
		vis2[u] = true;
		pa[u] = p;
		tin[u] = euler.size();
		euler.emplace_back(d[u],u);
		for (auto [v,idx]: adj2[u]){
			if (v == p) continue;
			d[v] = d[u] + 1;
			ip[v] = -idx;
			dfs2(v,u);
			euler.emplace_back(d[u],u);
		}
	};
	for (int i = 1; i <= n; ++i) if (!vis2[find(i)]) dfs2(find(i),find(i));
	//segment tree on euler tour array
	int len = euler.size();
	vector<pair<int,int>> tree(len*2,{INT_MAX,INT_MAX});
	for (int i = 0; i < len; ++i){
		tree[i+len] = euler[i];
	}
	for (int i = len-1; i; --i){
		tree[i] = min(tree[i*2],tree[i*2+1]);
	}
	function<pair<int,int>(int,int)> lca = [&](int a, int b){
		int l = min(tin[a],tin[b]), r = max(tin[a],tin[b])+1;
		pair<int,int> res = {INT_MAX,INT_MAX};
		for (l += len, r += len; l < r; l /= 2, r /= 2){
			if (l%2) res = min(res, tree[l++]);
			if (r%2) res = min(res, tree[--r]);
		}
		return res;
	};
	//sort queries non-decreasing depth
	vector<tuple<int,int,int,int>> queries;
	int p; cin >> p;
	for (int i = 0; i < p; ++i){
		int x,y; cin >> x >> y;
		x = find(x); y = find(y);
		if (x == y) continue; //already in same component
		auto lcaxy = lca(x,y);
		queries.emplace_back(lcaxy.first,lcaxy.second,x,y);
	}
	sort(queries.begin(),queries.end(),[](auto a, auto b){
		return get<0>(a) < get<0>(b);
	});
	for (auto[lcah,lca,x,y]: queries){
		for (int i = x; i != lca; i = pa[i]){
			char curdir = ip[i] < 0 ? 'L' : 'R';
			char& dir = ans[abs(ip[i])];
			if (dir == 'B' or dir == curdir) break;
			if (dir == '?') dir = curdir;
			else dir = 'B';
		}
		for (int i = y; i != lca; i = pa[i]){
			char curdir = ip[i] < 0 ? 'R' : 'L';
			char& dir = ans[abs(ip[i])];
			if (dir == 'B' or dir == curdir) break;
			if (dir == '?') dir = curdir;
			else dir = 'B';
		}
	}
	for (int i = 1; i <= m; ++i){
		cout << (ans[i] == '?' ? 'B' : ans[i]);
	}
	cout << "\n";
	return 0;
}