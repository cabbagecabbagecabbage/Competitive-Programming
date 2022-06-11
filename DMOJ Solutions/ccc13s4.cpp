#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n,m;
bool vis[maxn];
vector<int> adj[maxn];

bool bfs(int s, int e){
	queue<int> q;
	for (int i = 0; i < maxn; ++i) vis[i] = false;
	q.push(s);
	vis[s] = true;
	while (!q.empty()){
		int node = q.front(); q.pop();
		if (node == e) break;
		for (int v: adj[node]){
			if (!vis[v]){
				q.push(v);
				vis[v] = true;
			}
		}
	}
	return vis[e];
}

int32_t main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int x,y; cin >> x >> y;
		adj[x].emplace_back(y);
	}
	int p,q; cin >> p >> q;
	if (bfs(p,q)){
		cout << "yes" << "\n";
	}
	else if (bfs(q,p)){
		cout << "no" << "\n";
	}
	else {
		cout << "unknown" << "\n";
	}
	return 0;
}