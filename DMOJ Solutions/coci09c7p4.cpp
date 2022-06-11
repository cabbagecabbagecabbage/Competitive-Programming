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
#define eb emplace_back_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*

*/

struct node{
	int x,y,z,idx;
	node(int a, int b, int c, int i){
		x = a;
		y = b;
		z = c;
		idx = i;
	}
};
struct edge{
	int from,to,cost;
	edge(int a, int b, int c){
		from = a;
		to = b;
		cost = c;
	}
};

bool compx(node a, node b){
	return a.x < b.x;
}
bool compy(node a, node b){
	return a.y < b.y;
}
bool compz(node a, node b){
	return a.z < b.z;
}
bool compe(edge a, edge b){
	return a.cost < b.cost;
}

const int nax = 1e5+5;
int n,x,y,z;
int parent[nax], size[nax];
vector<node> nodesx;
vector<node> nodesy;
vector<node> nodesz;
vector<edge> edges;

void init(){
	f(n){
		parent[i] = i;
	}
}

int find(int node){
	return node == parent[node] ? node : parent[node] = find(parent[node]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (size[a] > size[b]) swap(a,b);
	parent[a] = b;
	size[b] += size[a];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f(n){
		in3(x,y,z);
		nodesx.emplace_back(node(x,y,z,i));
		nodesy.emplace_back(node(x,y,z,i));
		nodesz.emplace_back(node(x,y,z,i));
	}
	sort(nodesx.begin(),nodesx.end(),compx);
	sort(nodesy.begin(),nodesy.end(),compy);
	sort(nodesz.begin(),nodesz.end(),compz);
	
	f(n-1){
		edges.emplace_back(edge(nodesx[i].idx,nodesx[i+1].idx,min(
														abs(nodesx[i].x-nodesx[i+1].x),
													min(abs(nodesx[i].y-nodesx[i+1].y),
														abs(nodesx[i].z-nodesx[i+1].z)))));
		edges.emplace_back(edge(nodesy[i].idx,nodesy[i+1].idx,min(
														abs(nodesy[i].x-nodesy[i+1].x),
													min(abs(nodesy[i].y-nodesy[i+1].y),
														abs(nodesy[i].z-nodesy[i+1].z)))));
		edges.emplace_back(edge(nodesz[i].idx,nodesz[i+1].idx,min(
														abs(nodesz[i].x-nodesz[i+1].x),
													min(abs(nodesz[i].y-nodesz[i+1].y),
														abs(nodesz[i].z-nodesz[i+1].z)))));
	}
	sort(edges.begin(),edges.end(),compe);
	int ans = 0;
	init();
	for (edge e: edges){
		if (merge(e.from,e.to)){
			ans += e.cost;
		}
	}
	out(ans);
}




















//trailing lines ftw