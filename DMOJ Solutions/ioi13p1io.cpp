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
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
guess:
calculate eccentricity for every component. find radius of each
answer is biggest radius + second biggest radius + l
edit: missed a case of second biggest radius + third biggest radius + 2l
edit: missed another case of diameter within the components
*/

const int nax = 1e5+5;
int n,m,l,u,v,w;
vector<pii> adj[nax];
int parent[nax],height[nax][2],f[nax],g[nax], biggest[nax], radius[nax];
int component[nax];

int compidx;

int dfs1(int node, int prev){
	//label the component of the node, label the parent, find the 2 largest heights (dist to deepest descendant)
	component[node] = compidx;
	parent[node] = prev;
	for (pii x: adj[node]){
		int child = x.first, weight = x.second;
		if (x.first != prev){
			int h = dfs1(child,node) + weight;
			if (h > height[node][0]){
				height[node][1] = height[node][0];
				height[node][0] = h;
				biggest[node] =	child;
			}
			else height[node][1] = max(height[node][1],h);
		}
	}
	return height[node][0];
}

void dfs2(int node){
	//find f(child): the longest path from the child that goes through the child's sibling (go up once and come down)
	//to do this we need the 2 largest heights: if the child is not the one with largest height, then the answer is 
	//weight + biggest height, and if it is then the answer is weight + second biggest height
	int biggestkid = height[node][0];
	int secondbiggestkid = height[node][1];
	for (pii x: adj[node]){
		int child = x.first, weight = x.second;
		if (child == parent[node]) continue;
		if (child == biggest[node]){
			f[child] = weight + secondbiggestkid;
		}
		else f[child] = biggestkid + weight;
		dfs2(child);
	}
}

void dfs3(int node){
	//find g(child): the longest path from the child to a node not in the child's subtree. (must go up at least once)
	//recursively g(child) = max(f(child),g(parent)+weight)
	for (pii x: adj[node]){
		int child = x.first, weight = x.second;
		if (child == parent[node]) continue;
		g[child] = max(f[child], g[node] + weight);
		dfs3(child);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in3(n,m,l);
	f(m){
		in3(u,v,w);
		adj[u].eb(v,w);
		adj[v].eb(u,w);
	}
	compidx = 1;
	f(n){
		if (component[i]==0){
			dfs1(i,-1);
			dfs2(i);
			dfs3(i);
			compidx++;
		}
	}
	mem(radius,infb);
	int ans = 0;
	f(n){
		radius[component[i]] = min(radius[component[i]], max(height[i][0], g[i]));
		ans = max(ans,max(height[i][0],g[i]));
		
	}
	f(nax){
		if (radius[i] == inf) radius[i] = 0;
	}
	// f2(1,compidx) out(radius[i]);
	sort(radius,radius+n,greater<int>());
	int a = radius[0], b = radius[1], c = radius[2];
	
	if (compidx > 2) ans = max(ans,a+b+l);
	if (compidx > 3) ans = max(ans,c+b+l+l);
	out(ans);
	return 0;
}




















//trailing lines ftw