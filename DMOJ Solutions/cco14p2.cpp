#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

/*
dijkstra from a with normal edges and from b with reversed edges
iterate over edges and push total lengths into vector. sort vector
take d's and sort them. iterate thru both sorted vectors simultaneously to answer the queries
*/

struct Edge{
	int x,y,l,c;
};

const int nax = 1e5 + 5, inf = 0x3f3f3f3f;
int n,m,a,b,q,ans[nax],dist[nax],dist2[nax];
vector<pair<int,int>> adj[nax], adj2[nax], canshutdown, query;
vector<Edge> edges;

void dij(int start){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dist[start] = 0;
	pq.push({0,start});
	while (!pq.empty()){
		int cost, node; tie(cost,node) = pq.top(); pq.pop();
		if (cost != dist[node]) continue;
		for (pair<int,int> nextnode: adj[node]){
			if (nextnode.second + cost < dist[nextnode.first]){
				dist[nextnode.first] = nextnode.second + cost;
				pq.push({dist[nextnode.first],nextnode.first});
			}
		}
	}
}

void dij2(int start){
	memset(dist2, 0x3f, sizeof(dist2));
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dist2[start] = 0;
	pq.push({0,start});
	while (!pq.empty()){
		int cost, node; tie(cost,node) = pq.top(); pq.pop();
		if (cost != dist2[node]) continue;
		for (pair<int,int> nextnode: adj2[node]){
			if (nextnode.second + cost < dist2[nextnode.first]){
				dist2[nextnode.first] = nextnode.second + cost;
				pq.push({dist2[nextnode.first],nextnode.first});
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; ++i){
		int x,y,l,c; cin >> x >> y >> l >> c;
		adj[x].emplace_back(y,l);
		adj2[y].emplace_back(x,l);
		edges.push_back({x,y,l,c});
	}
	dij(a); dij2(b);
	//iterate over edges
	for (Edge e: edges){
		int totaldist = -1;
		if (dist[e.x] != inf and dist2[e.y] != inf){
			totaldist = dist[e.x] + dist2[e.y] + e.l;
		}
		if (totaldist != -1){
			canshutdown.emplace_back(totaldist,e.c);
		}
	}
	//sort
	sort(canshutdown.begin(), canshutdown.end());
	//handle queries
	cin >> q;
	for (int i = 0; i < q; ++i){
		int d; cin >> d;
		query.emplace_back(d,i);
	}
	sort(query.begin(),query.end());
	int presum = 0, pointer = -1, l = canshutdown.size();
	for (int i = 0; i < q; ++i){
		while (pointer+1 < l and canshutdown[pointer+1].first <= query[i].first){
			presum += canshutdown[++pointer].second;
		}
		ans[query[i].second] = presum;
	}
	for (int i = 0; i < q; ++i) cout << (ans[i]) << "\n";
	return 0;
}