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

*/
const int nax = 1e5+5;
int n,m,k,x,y,a,b;
vi adj[nax];
int compidx;
int comp[nax],race[nax],vis[nax];
string all;

void dfs(int node){
	vis[node] = 1;
	comp[node] = compidx;
	for (int x: adj[node]){
		if (!vis[x]) dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in3(n,m,k);
	in(all);
	f(all.length()){
		if (all[i] == 'P') race[i+1] = 1;
		elif (all[i] == 'T') race[i+1] = 2;
		elif (all[i] == 'Z') race[i+1] = 3;
	}
	f(m){
		in2(a,b);
		if (race[a] == race[b]){
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	compidx = 1;
	f2(1,n+1){
		if (!vis[i]){
			dfs(i);
			compidx++;
		}
	}
	int ans = 0;
	
	f(k){
		in2(x,y);
		if (comp[x] == comp[y]) ans++;
	}
	out(ans);


	return 0;
}




















//trailing lines ftw