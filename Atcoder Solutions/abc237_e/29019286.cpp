#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n,m,dist[maxn],h[maxn];
vector<int> adj[maxn];

int32_t main(){
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> h[i];
	}
	for (int i = 1; i <= m; ++i){
		int u,v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	typedef pair<int,int> pii;
	priority_queue<pii,vector<pii>,greater<>> pq;
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	pq.emplace(0,1);
	while (!pq.empty()){
		auto [cost,node] = pq.top(); pq.pop();
		if (dist[node] != cost) continue;
		for (int v: adj[node]){
			int newdist = cost + max(0,h[v] - h[node]);
			if (newdist < dist[v]){
				dist[v] = newdist;
				pq.emplace(newdist,v);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		ans = max(ans, h[1] - h[i] - dist[i]);
	}
	cout << ans << "\n";
	return 0;
}