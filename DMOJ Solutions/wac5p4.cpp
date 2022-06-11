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
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
1. find midpoint between a and c
	- calc lca(a,c)
	- take depth[a] + depth[c] - 2 * depth[lca(a,c)]
	- if the distance if odd then we cant find a middle vertex
	- take half the distance from a to c
	- try to walk up that distance from a. if that goes off the path, try to walk that distance from c.
	
2. Check if (x is on the path from a to b) AND (x is on the path from c to d)
	- to check whether x is on the path from u to v, check if {lca(u,v),x} is the same set as {lca(x,u),lca(x,v)}
	we can prove by casework
	if x is lca(u,v), then {x,x} = {x,x}
	if lca(u,v) lies between u and x, then lca(u,v) = lca(u,x) and x = lca(x,v)
	by symmetry if lca(u,v) lies between v and x, this also holds
*/
const int nax = 2e5+5;
int n,q,x,y,a,b,c,d,depth[nax];
int preorder[nax],postorder[nax];
vi adj[nax];

const int logn = ceil(log2(nax));
int up[nax][logn+1];

int timer = 0;

void dfs(int node, int par){
	preorder[node] = ++timer;
	depth[node] = depth[par] + 1;
	up[node][0] = par;
	for (int i = 1; i <= logn; i++) up[node][i] = up[up[node][i-1]][i-1];
	for (int x: adj[node]) if (x != par) dfs(x,node);
	postorder[node] = ++timer;
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

int dist(int u, int v){
	return depth[u] + depth[v] - 2 * depth[lca(u,v)];
}

bool liesOn(int x, int start, int end){
	int startend = lca(start,end);
	int startx = lca(start,x);
	int xend = lca(x,end);
	return (startend == startx && x == xend) || (startend == xend && x == startx);
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,q);
	f(n-1){
		in2(x,y);
		adj[x].eb(y);
		adj[y].eb(x);
	}
	//preprocess
	dfs(1,1);
	
	//answer queries
	while (q--){
		in2(a,b);in2(c,d);
		//find midpoint
		int ac = lca(a,c);
		int actoa = depth[a] - depth[ac];
		int actoc = depth[c] - depth[ac];
		int atoc = actoa + actoc;
		if (atoc % 2){
			out(-1);
			continue;
		}
		int halfatoc = atoc / 2;
		int midpoint = walkup(a,halfatoc);
		if (isAncestor(midpoint,ac)) midpoint = walkup(c,halfatoc);
		
		if (liesOn(midpoint,a,b) && liesOn(midpoint,c,d) && midpoint != b && midpoint != d){
			out(dist(a,midpoint));
		}
		else out(-1);	 
	}
	return 0;
}




















//trailing lines ftw