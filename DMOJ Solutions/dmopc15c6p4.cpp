#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*

*/
struct edge{
	int from, to, c;
	edge(int q, int w, int e){
		from = q;
		to = w;
		c = e;
	}
};

const int nax = 1e5 + 5;

vector<edge> edges;
int parent[nax],size[nax],n,k,w;

int find(int node){
	return node == parent[node] ? node : parent[node] = find(parent[node]);
}

bool merge(int a, int b){
	a = find(a); b = find(b);
	if (a == b) return false;
	if (size[a] > size[b]) swap(a,b);
	parent[a] = b;
	size[b] += size[a];
	return true;
}

bool c(edge a, edge b){
	return a.c < b.c;
}



int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,k);
	f2(1,n){
		in(w);
		edges.eb(edge(i,i+1,w));
		if (i+k <= n) edges.eb(edge(i,i+k,0));
	}
	sort(edges.begin(),edges.end(),c);
	int ans = 0;
	f(n+1) parent[i] = i;
	for (edge e: edges){
		if (merge(e.from,e.to)) ans += e.c;
	}
	out(ans);
	return 0;
}




















//trailing lines ftw