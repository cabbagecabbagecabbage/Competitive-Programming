#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n,k; cin >> n >> k;
	vector<vector<pair<int,int>>> adj(n+1), delim(n+1);
	for (int i = 1; i < n; ++i){
		int a,b,d; cin >> a >> b >> d;
		adj[a].emplace_back(d,b);
		adj[b].emplace_back(d,a);
	}
	vector<int> pandas(k),ans(n+1);
	for (auto& k: pandas) cin >> k;
	sort(pandas.begin(),pandas.end());
	ans[1] = k;
	function<void(int,int,int,int)> dfs = [&](int u, int p, int l, int r){
		sort(adj[u].begin(),adj[u].end());
		for (auto[d,v]: adj[u]){
			if (v == p){
				adj[u].erase(lower_bound(adj[u].begin(),adj[u].end(),make_pair(d,v)));
				break;
			}
		}
		for (int i = 0; i < adj[u].size(); ++i){
			int d,v; tie(d,v) = adj[u][i];
			int lb = l, rb = r;
			//in the [l,r] range of pandas, find the interval belonging to the current hill
			int ql = i == 0 ? 0 : (adj[u][i-1].first + d) / 2 + 1;
			int qr = i == adj[u].size()-1 ? 1e9+5 : (adj[u][i+1].first + d) / 2;
			//bs for most left such that l1 >= lb and pandas[l1] >= ql
			int l1 = INT_MAX, r1 = INT_MIN;
			while (lb <= rb){
				int mid = (lb + rb) / 2;
				if (pandas[mid] >= ql){
					l1 = mid;
					rb = mid - 1;
				}
				else lb = mid + 1;
			}
			lb = l, rb = r;
			while (lb <= rb){
				int mid = (lb + rb) / 2;
				if (pandas[mid] <= qr){
					r1 = mid;
					lb = mid + 1;
				}
				else rb = mid - 1;
			}
			ans[v] = max(0ll,r1 - l1 + 1);
			if (l1 <= r1) dfs(v,u,l1,r1);
		}
	};
	dfs(1,1,0,k-1);
	for (int i = 1; i <= n; ++i){
		cout << ans[i] << " \n"[i==n];
	}
	return 0;
}