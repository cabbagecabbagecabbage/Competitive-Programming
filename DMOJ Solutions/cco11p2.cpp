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
dist[node][i] stores the shortest distance to node while being exposed for i seconds
*/

const int nax = 1600 + 5;
int dist[nax][3605];
vector<pii> adj[nax][2];
queue<pii> q;
bool inq[nax][3605];
int s,n,e,a,b,d,u;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	mem(dist,infb);
	in(s);
	in2(n,e);
	f(e){
		in2(a,b); in2(d,u);
		if (u){
			adj[a][1].eb(b,d);
			adj[b][1].eb(a,d);
		}
		else {
			adj[a][0].eb(b,d);
			adj[b][0].eb(a,d);
		}	
	}
	//0 to n-1
	inq[0][0] = true;
	dist[0][0] = 0;
	q.push({0,0});
	int cost, node, dest, dtime, newcost, newdayl;
	while (!q.empty()){
		tie(cost,node) = q.front(); q.pop();
		inq[node][cost] = false;
		
		//underground
		for (pii x: adj[node][0]){
			tie(dest, dtime) = x;
			newcost = dist[node][cost] + dtime;
			if (newcost < dist[dest][cost]){
				dist[dest][cost] = newcost;
				if (!inq[dest][cost]){
					inq[dest][cost] = true;
					q.push({cost,dest});
				}
			}
		}
		
		//not underground
		for (pii x: adj[node][1]){
			tie(dest, dtime) = x;
			newdayl = cost + dtime;
			if (newdayl > s) continue;
			newcost = dist[node][cost] + dtime;
			if (newcost < dist[dest][newdayl]){
				dist[dest][newdayl] = newcost;
				if (!inq[dest][newdayl]){
					inq[dest][newdayl] = true;
					q.push({newdayl,dest});
				}
			}
		}
	}
	
	int ans = inf;
	f(s+1) ans = min(ans,dist[n-1][i]);
	out((ans == inf ? -1 : ans));

	return 0;
}




















//trailing lines ftw