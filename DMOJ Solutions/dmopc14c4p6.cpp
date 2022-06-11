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
https://cs.stackexchange.com/questions/74210/efficient-algorithm-to-compute-radius-of-tree
*/
const int nax = 5e5+5;
int n,u,v,w;
vi adj[nax];
int parent[nax],height[nax][3],f[nax],g[nax], biggest[nax];

int dfs1(int node, int prev){
	parent[node] = prev;
	for (int x: adj[node]){
		int child = x, weight = 1;
		if (x != prev){
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
	int biggestkid = height[node][0];
	int secondbiggestkid = height[node][1];
	for (int x: adj[node]){
		int child = x, weight = 1;
		if (child == parent[node]) continue;
		if (child == biggest[node]){
			f[child] = weight + secondbiggestkid;
		}
		else f[child] = biggestkid + weight;
		dfs2(child);
	}
}

void dfs3(int node){
	for (int x: adj[node]){
		int child = x, weight = 1;
		if (child == parent[node]) continue;
		g[child] = max(f[child], g[node] + weight);
		dfs3(child);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f(n-1){
		in2(u,v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	//root tree at 1
	dfs1(1,0); //find parent and height
	dfs2(1); //find f(node) = longest path in the parents' subtree (go up once then come down) starting from node
	dfs3(1); //find g(node) = longest path in the tree aside from current subtree (must go up) starting from node
	f2(1,n+1){
		out(max(height[i][0], g[i])+1); //eccentricity = (longest path in subtree, longest path not in subtree)
	}
	


	return 0;
}




















//trailing lines ftw