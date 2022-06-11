#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
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
dijkstra both ways
try each edge and minimize while making sure its longer than shortest
*/
const int nax = 10005, mmax = 10000;
int forw[nax], back[nax];
vector<pii> adj[nax];
vector<tuple<int,int,int>> edges;
int n,m,a,b,l;
int visited[nax];
int bvisited[nax];
priority_queue<pii,vector<pii>,greater<pii>> q;

void dij(){
	mem(forw,0x3f);
	q.push(mp(0,1));
	visited[1] = 1;
	forw[1] = 0;
	int cost,node;
	while (!q.empty()){
		tie(cost,node) = q.top();q.pop();
		if (cost != forw[node]) continue;
		for (pii x: adj[node]){
			if (forw[x.first] > forw[node] + x.second){
				forw[x.first] = forw[node] + x.second;
				visited[x.first] = 1;
				q.push(mp(forw[x.first],x.first));
			}
		}
	}
}

void dijrev(){
	mem(back,0x3f);
	q.push(mp(0,n));
	bvisited[n] = 1;
	back[n] = 0;
	int cost,node;
	while (!q.empty()){
		tie(cost,node) = q.top();q.pop();
		if (cost != back[node]) continue;
		for (pii x: adj[node]){
			if (back[x.first] > back[node] + x.second){
				back[x.first] = back[node] + x.second;
				bvisited[x.first] = 1;
				q.push(mp(back[x.first],x.first));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f(m){
		in3(a,b,l);
		edges.pb({a,b,l});
		edges.pb({b,a,l});
		adj[a].pb(mp(b,l));
		adj[b].pb(mp(a,l));
	}
	dij();
	dijrev();
	int shortest = forw[n];
	int second = inf;
	f(2*m){
		tie(a,b,l) = edges[i];
		int newcost = forw[a] + back[b] + l;
		if (newcost > shortest && newcost < second){
			second = newcost;
		}
	}
	
	out(((second==inf ? -1 : second)));

	return 0;
}




















//trailing lines ftw