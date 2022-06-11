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

const int nax = 2e5 + 5;
int n,m,a,b,p;
priority_queue<pii> q;
vpii adj[nax];
int dist[nax];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f(m){
		in3(a,b,p);
		adj[a].eb(b,p);
		adj[b].eb(a,p);
	}
	//1 to everywhere
	// mem(dist,infb);
	int cost, node, newcost;
	q.push({inf,1});
	while (!q.empty()){
		tie(cost,node) = q.top(); q.pop();
		if (cost != dist[node] && node != 1) continue;
		for (pii x: adj[node]){
			newcost = min(x.second,cost);
			if (newcost > dist[x.first]){
				dist[x.first] = newcost;
				q.push({newcost,x.first});
			}
		}
	}
	dist[1] = 0;
	f2(1,n+1) out(dist[i]);
	return 0;
}




















//trailing lines ftw