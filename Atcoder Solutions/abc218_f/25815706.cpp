
// Problem: F - Blocked Roads
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

/*
ind[a][b] stores the indices of the edge going from a to b

dist[node] stores min cost from 1 to N
pre[node] stores the previous node on the path that incurred the min cost
bfs to find a path from 1 to n to compute

first fill all ans[edge] as dist[node]

iterate thru path from 1 to n backwards: for every edge
	remove b from adj[a]
	bfs to find shortest path to n, replace into ans[ind[a][b]]
	add b to adj[a]
*/

const int nax = 4e2 + 5;
int n,m,ind[nax][nax],ans[nax*nax],dist[nax],pre[nax];
set<int> adj[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int s, t; cin >> s >> t;
		adj[s].insert(t);
		ind[s][t] = i;
	}
	queue<int> q;
	q.push(1);
	memset(dist,0x3f, sizeof dist);
	dist[1] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int v: adj[u]){
			if (dist[u] + 1 < dist[v]){
				pre[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	for (int i = 0; i < m; ++i){
		ans[i] = (dist[n] == 0x3f3f3f3f ? -1 : dist[n]);
	}
	if (dist[n] != 0x3f3f3f3f){
		for (int node = n; node != 1; node = pre[node]){
			int u = pre[node], v = node;
			adj[u].erase(v);
			q.push(1);
			memset(dist,0x3f,sizeof dist);
			dist[1] = 0;
			while (!q.empty()){
				int a = q.front(); q.pop();
				for (int b: adj[a]){
					if (dist[a] + 1 < dist[b]){
						dist[b] = dist[a] + 1;
						q.push(b);
					}
				}
			}
			ans[ind[u][v]] = (dist[n] == 0x3f3f3f3f ? -1 : dist[n]);
			adj[u].insert(v);
		}
	}
	for (int i = 0; i < m; ++i){
		cout << ans[i] << "\n";
	}
	
	return 0;
}