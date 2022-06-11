#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma,sse4,avx2")
#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n,m; cin >> n >> m;
	vector<string> grid(n);
	vector<vector<int>> id(n,vector<int>(m));
	for (int i = 0; i < n; ++i){
		cin >> grid[i];
		for (int j = 0; j < m; ++j){
			id[i][j] = i*m+j;
		}
	}
	vector<int> par(n*m+2), siz(n*m+2,1);
	for (int i = 0; i < n*m+2; ++i) par[i] = i;
	function<int(int)> find = [&](int node){
		return par[node] = node == par[node] ? node : find(par[node]);
	};
	auto merge = [&](int a, int b){
		a = find(a); b = find(b);
		if (a == b) return;
		if (siz[a] > siz[b]) swap(a,b);
		par[a] = b;
		siz[b] += siz[a];
	};
	//connect land cells
	if (n >= 2 and m >= 2){
		if (grid[0][0] == '#' and grid[0][1] == '#') merge(id[0][0],id[0][1]);
		if (grid[0][0] == '#' and grid[1][0] == '#') merge(id[0][0],id[1][0]);
	}
	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			if (grid[i][j] == '#'){
				if (grid[i-1][j] == '#'){
					merge(id[i][j],id[i-1][j]);
				}
				if (grid[i][j-1] == '#'){
					merge(id[i][j],id[i][j-1]);
				}
			}
		}
	}
	vector<tuple<int,int,int>> edges;
	//make puddle edges
	for (int i = 0; i < n; ++i){
		//horizontal
		int lastland = -1;
		for (int j = 0; j < m-1; ++j){
			if (grid[i][j] == '.'){
				if (grid[i][j+1] == '#' and lastland != -1){
					int pl = find(id[i][lastland]), pr = find(id[i][j+1]);
					if (pl != pr){
						edges.emplace_back(j-lastland,pl,pr);
					}
				}
			}
			else lastland = j;
		}
	}
	for (int j = 0; j < m; ++j){
		//vertical
		int lastland = -1;
		for (int i = 0; i < n-1; ++i){
			if (grid[i][j] == '.'){
				if (grid[i+1][j] == '#' and lastland != -1){
					int pl = find(id[lastland][j]), pr = find(id[i+1][j]);
					if (pl != pr){
						edges.emplace_back(i-lastland,pl,pr);
					}
				}
			}
			else lastland = i;
		}
	}
	int top = n*m;
	for (int i = 0; i < m; ++i){
		merge(top,id[0][i]);
	}
	sort(edges.begin(),edges.end(),[](auto a, auto b){
		return get<0>(a) > get<0>(b);
	});
	vector<int> ans(m,-1);
	for (int i = 0; i < m; ++i){
		if (find(top) == find(id[n-1][i])){
			ans[i] = 0;
		}
	}
	int lastcost = INT_MAX;
	for (auto[a,b,c]: edges){
		// cout << a << " " << b << " " << c << "\n";
		if (a != lastcost){
			for (int i = 0; i < m; ++i){
				if (ans[i] == -1 and find(top) == find(id[n-1][i])){
					ans[i] = lastcost;
				}
			}
		}
		merge(b,c);
		lastcost = a;
	}
	for (int i = 0; i < m; ++i){
		if (ans[i] == -1 and find(top) == find(id[n-1][i])){
			ans[i] = lastcost;
		}
	}
	for (int i = 0; i < m; ++i){
		cout << ans[i] << " \n"[i == m-1];
	}
	return 0;
}