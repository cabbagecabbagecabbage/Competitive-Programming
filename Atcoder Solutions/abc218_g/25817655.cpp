#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define int long long
/*

*/

const int nax = 1e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n,a[nax],timer = 0;
vector<int> adj[nax];
ost s;

int dfs(int u, int p, int isTaro){
	s.insert({a[u],timer++});
	if (adj[u].size() == 1 and u != 1){
		int ret;
		if (s.size() % 2){
			ret = (*s.find_by_order(s.size() / 2)).first;
		}
		else {
			ret = ((*s.find_by_order(s.size() / 2)).first + (*s.find_by_order(s.size() / 2 - 1)).first) / 2;
		}
		s.erase({a[u], --timer});
		return ret;
	}
	int small = inf, big = -inf;
	for (int v: adj[u]){
		if (v == p) continue;
		int res = dfs(v, u, !isTaro);
		small = min(res, small);
		big = max(res, big);
	}
	s.erase({a[u],--timer});
	if (isTaro) return big;
	else return small;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i){
		int a,b; cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	cout << dfs(1,0,1) << "\n";
	
	return 0;
}