#include <bits/stdc++.h>
using namespace std;

unordered_set<int> adj[9], adj2[9];

int32_t main(){
	int n,m; cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a,b; cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	for (int i = 0; i < m; ++i){
		int c,d; cin >> c >> d;
		adj2[c].insert(d);
		adj2[d].insert(c);
	}
	vector<int> p;
	for (int i = 1; i <= n; ++i) p.emplace_back(i);
	do {
		bool ok = true;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (adj[i].count(j) and !adj2[p[i-1]].count(p[j-1])){
					ok = false;
				}
			}
		}
		if (ok){
			cout << "Yes";
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << "No";
	return 0;
}