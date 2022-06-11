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
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
dsu
keep an edge list
keep track of whether an edge was a connecting edge
*/
struct Edge{
	int from, to;
	bool connecting;
};

const int nax = 5e5+5;
int parent[nax], size[nax];
stack<Edge> edges;

int find(int node){
	if (parent[node] == node) return node;
	return find(parent[node]);
}

void Init(int N){
	f2(1,N+1){
		parent[i] = i;
		size[i] = 1;
	}
}

void AddEdge(int U, int V){
	Edge cur;
	int parentu = find(U), parentv = find(V);
	cur.from = parentu;
	cur.to = parentv;
	cur.connecting = (parentu != parentv);
	if (cur.connecting){
		if (size[parentv] > size[parentu]){
			parent[parentu] = parentv;
			size[parentv] += size[parentu];
			cur.from = parentu;
			cur.to = parentv;
		}
		else{
			parent[parentv] = parentu;
			size[parentu] += size[parentv];
			cur.to = parentu;
			cur.from = parentv;
		}
	}
	edges.push(cur);
}

void RemoveLastEdge(){
	Edge last = edges.top(); edges.pop();
	int U = last.from, V = last.to;
	if (!last.connecting) return;
	parent[U] = U;
	size[V] -= size[U];
}

int GetSize(int U){
	return size[find(U)];
}
	

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	return 0;
}




















//trailing lines ftw