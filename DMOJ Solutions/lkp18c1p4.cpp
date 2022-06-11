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
typedef pair<long long, long long> pii;


/*
binary search it? idk
*/
const int nax = 1e5+5;
long long n,m,a,b,c,A,B,C;
long long dist[nax];
vector<pair<int,pii>> adj[nax];

int dijkstra(int cap) {
    mem(dist,infb);
    dist[A] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, A});
    dist[A] = 0;
	
	int cost, node;
    while (!q.empty()) {
        tie(cost,node) = q.top(); q.pop();
        if (cost != dist[node]) continue;
        for (pair<int,pii> x: adj[node]){
        	if (x.first > cap) break;
        	int nextnode = x.second.first;
        	int newcost = dist[node] + x.second.second;
        	if (newcost < dist[nextnode]){
        		q.push(mp(newcost,nextnode));
        		dist[nextnode] = newcost;
        	}
        }
    }
    return dist[B] < C ? 1 : 0;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f2(1,m+1){
		in3(a,b,c);
		adj[a].pb(mp(i,mp(b,c)));
		adj[b].pb(mp(i,mp(a,c)));
	}
	in3(A,B,C);
	//inclusive cap
	int hi = m, lo = 1, ans = 0;
	while (hi >= lo){
		int mid = (hi + lo) / 2;
		if (dijkstra(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	if (ans) out(ans);
	else out(-1);
	return 0;
}




















//trailing lines ftw