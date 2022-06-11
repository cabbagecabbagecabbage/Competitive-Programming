#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a;
#define in2(a,b) cin >> a >> b;
#define in3(a,b,c) cin >> a >> b >> c;
#define out(a) cout << a << endl;
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
excluding all the special edges, we find the shortest distance to every node in the graph forwards and backwards
now try to incorporate each edge into a path to see if it makes it shorter
*/

vector<pii> graph[500005], revgraph[500005];
int inq[500005], back[500005], forw[500005];

queue <int> q;

void spfa(int start, vector<pii> (&g)[500005], int (&dist)[500005]) {
	mem(inq,0);
	mem(dist,inf);
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        inq[node] = 0;
        for (pii x: g[node]) {
            int dest = x.first;
            int newcost = dist[node] + x.second;
            if (dist[dest] > newcost) {
                dist[dest] = newcost;
                if (!inq[dest]) {
                    q.push(dest);
                    inq[dest] = 1;
                }
            }
        }
    }
}
int n, m;
vector<tuple<int,int,int>> secret;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	int a,b,k;
	f(m){
		in3(a,b,k);
		graph[a].pb(mp(b,k));
		revgraph[b].pb(mp(a,k));
	}
	int d, g;
	in(d);
	f(d){
		in3(a,b,g);
		secret.pb(make_tuple(a,b,g));
	}
	spfa(1,graph,forw);
	spfa(n,revgraph,back);
	// f(n) cout << forw[i] << endl;
	// f(n) cout << back[i] << endl;
	int from, to, weight;
	int ans = forw[n]; //assume the best does not use secret pathways at first
	for (tuple<int,int,int> x: secret){
		tie(from,to,weight) = x;
		ans = min(ans,forw[from]+weight+back[to]);
	}

	if(ans==inf) out(-1)
	else out(ans);
	return 0;
}




















//trailing lines ftw