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

typedef tuple<double,int,int> tiii;
/*

*/

const int nax = 1e3 + 5;
vector<pair<int,double>> adj[nax];
int v,e,m,n;
double d,s;
int edges[nax];
double dist[nax];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(v,e);
	f(e){
		in2(m,n);in2(d,s);
		double actualtime = d / s * 60;
		adj[m].eb(n,actualtime);
		adj[n].eb(m,actualtime);
	}
	// 1 to v
	
	priority_queue<tiii,vector<tiii>,greater<tiii>> q;
	q.push({0.0d,0,1});
	f(v+1) dist[i] = 100000000.0d, edges[i] = 100000000; 
	dist[1] = 0.0d;
	edges[1] = 0;
	double cost; int edgecount, node;
	while (!q.empty()){
		tie(cost,edgecount,node) = q.top(); q.pop();
		// out(node);
		// out2(cost,edgecount);
		if (cost != dist[node] || edgecount != edges[node]) continue;
		for (pair<int,double> x: adj[node]){
			double newcost = x.second + cost;
			if (newcost < dist[x.first] || (newcost == dist[x.first] && edgecount + 1 < edges[x.first])){
				edges[x.first] = edges[node] + 1;
				dist[x.first] = newcost;
				q.push({dist[x.first],edges[x.first],x.first});
			}
		}
	}
	
	out(edges[v]);
	const double mul = 1.0d/3;
	out( (int) (round(dist[v]*mul)));

	return 0;
}




















//trailing lines ftw