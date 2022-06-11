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


/*
case 1 u before v:
	The length of the path is therefore the first[v] - first[x] - (depth[u] - depth[x])
	imagine if we started at x. then we would traverse the subtree rooted at x until we reach v
	which gives us first[v] - first[x]
	since we are starting at u, the edges from u to x are no longer traced twice (unlike every other edge in an euler tour)
	
case 2 v before u:
	we can again use the lca 
	we can split it into sections of from u to x and from x to v
	we know that from u to x we have to traverse every edge in the entire subtree that is rooted 1 lower than x (that leads to u) twice, except the path from u to x
	this can be done by walking node u (depth[u] - depth[x] - 1) to find that node 1 lower than x, then finding the number of edges in the subtree * 2, then adding the one edge from the node up to x, then subtracting the path from u to x
	
*/

const int nax = 1e5 + 5;
const int logn = ceil(log2(nax));

int up[nax][logn+1];

vi adj[nax];
int depth[nax], size[nax];
int preorder[nax], postorder[nax];

int n,c,child,q;

int timer = 0;

int dfs(int node, int par){
	preorder[node] = ++timer;
	depth[node] = depth[par] + 1;
	up[node][0] = par;
	for (int i = 1; i <= logn; i++) up[node][i] = up[up[node][i-1]][i-1];
	for (int x: adj[node]) if (x != par) size[node] += dfs(x,node) + 1;
	postorder[node] = ++timer;
	return size[node];
}

bool isAncestor(int u, int v){
	return (preorder[u] <= preorder[v] && postorder[u] >= postorder[v]);
}

int lca(int u, int v){
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = logn; i >= 0; --i) if (!isAncestor(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int walkup(int node, int dist){
	for (int i = logn; i >= 0; i--){
		if ((1 << i) & dist){
			node = up[node][i];
		}
	}
	return node;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f2(1,n+1){
		in(c);
		ff(c){
			in(child);
			adj[i].pb(child);
		}
	}
	dfs(1,1);
	int u,v;
	in(q);
	f(q){
		in2(u,v);
		int uv = lca(u,v);
		if (preorder[u] < preorder[v]){
			//case 1
			out((preorder[v] - preorder[uv] - (depth[u] - depth[uv])));
		}
		elif (preorder[v] < preorder[u]){
			//case 2
			int sub = walkup(u,(depth[u] - depth[uv] - 1));
			out((size[sub]*2 - (depth[u] - depth[sub]) + 1 + preorder[v] - preorder[uv]));
		}
		else out(0);
	}



	return 0;
}




















//trailing lines ftw