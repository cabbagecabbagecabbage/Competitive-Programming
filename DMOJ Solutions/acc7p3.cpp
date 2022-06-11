#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5;
int n,m,parent[nax],size[nax];
pair<int,int> arr[nax];

struct edge{
	int a,b,c;
};
vector<edge> edges;

int Find(int node){
	if (node == parent[node]) return node;
	else return parent[node] = Find(parent[node]);
}

bool Merge(int a, int b){
	a = Find(a), b = Find(b);
	if (a == b) return false;
	if (size[a] > size[b]) swap(a,b);
	size[b] += size[a];
	parent[a] = b;
	return true;
}



int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		int f; cin >> f;
		arr[i] = {f,i};
	}
	sort(arr+1,arr+n+1);
	for (int i = 1; i < n; ++i){
		edges.push_back({i,i+1,arr[i+1].first-arr[i].first});
	}
	while (m--){
		int a,b; cin >> a >> b;
		edges.push_back({a,b,0});
	}
	sort(edges.begin(),edges.end(),[](edge a, edge b){
		return a.c < b.c;
	});
	int cost = 0;
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		size[i] = 1;
	}
	for (edge k: edges){
		if (Merge(k.a,k.b)){
			cost += k.c;
		}
	}
	cout << cost << "\n";	
	return 0;
}