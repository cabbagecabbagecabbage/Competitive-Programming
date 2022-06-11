#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,m;
int dist[100005];
vector<int> adj[100005];
int ans = 0;

int dfs(int node){
	if (dist[node]!=-1) return dist[node];
	int longest = 0;
	for (int nex: adj[node]){
		longest = max(longest,dfs(nex)+1);
	}
	ans = max(ans,longest);
	return dist[node]=longest;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    f(m){
    	int a,b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    }
    mem(dist,-1);
    f2(1,n+1){
    	if (dist[i]==-1){
    		dfs(i);
    	}
    }
    cout << ans << endl;

 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}