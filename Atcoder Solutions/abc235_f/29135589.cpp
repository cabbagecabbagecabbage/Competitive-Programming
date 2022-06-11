#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
vector<int> parent(maxn+1),s(maxn+1);

int find(int node){
	return parent[node] = node == parent[node] ? node : find(parent[node]);
}

void merge(int a, int b){
	a = find(a); b = find(b);
	if (a == b) return;
	if (s[a] > s[b]) swap(a,b);
	parent[a] = b;
	s[b] += s[a];
}

int32_t main(){
	int n,m,q;
	cin >> n >> m >> q;
	vector<tuple<int,int,int,int>> edges;
	for (int i = 0; i < m; ++i){
		int a,b,c; cin >> a >> b >> c;
		edges.emplace_back(c,a,b,-1);
	}
	for (int i = 0; i < q; ++i){
		int u,v,w; cin >> u >> v >> w;
		edges.emplace_back(w,u,v,i);
	}
	sort(edges.begin(),edges.end());
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		s[i] = 1;
	}
	vector<bool> ans(q,false);
	for (auto[c,a,b,idx]: edges){
		if (find(a) != find(b)){
			if (idx != -1){
				ans[idx] = true;
			}
			else {
				merge(a,b);
			}
		}
	}
	for (int i = 0; i < q; ++i){
		cout << (ans[i] ? "Yes" : "No") << "\n";
	}
	return 0;
}