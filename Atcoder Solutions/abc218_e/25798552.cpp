
// Problem: E - Destruction
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
/*

*/

const int nax = 2e5 + 5;
int n,m,parent[nax], s[nax];
struct edge {
	int a,b,c;
} edges[nax];

int Find(int node){
	return (node == parent[node] ? node : Find(parent[node]));
}

void Merge(int a, int b){
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (s[a] > s[b]) swap(a,b);
	parent[a] = b;
	s[b] += s[a];
}

bool c(edge a, edge b) {return a.c < b.c;}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
	}
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		s[i] = 1;
	}
	sort(edges, edges + m,c);
	int ans = 0;
	for (int i = 0; i < m; ++i){
		if (edges[i].c <= 0 or Find(edges[i].a) != Find(edges[i].b)){
			Merge(edges[i].a, edges[i].b);
		}
		else ans += edges[i].c;
	}
	cout << ans << "\n";
	return 0;
}