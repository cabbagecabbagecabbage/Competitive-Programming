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
#define pb push_back
#define mp make_pair
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;

int dist[1001];
vector<pii> adj[1001];
int n,m;
queue<int> q;

/*
set dist to every node as inf except 1
start at 1
for every neighbor
if the cost at current node + cost of edge < dist[next node]
then update the dist and put node in queue
*/

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a,b,c;
    f(m){
    	cin >> a >> b >> c;
    	adj[a].pb(mp(b,c));
    }
	mem(dist,0x3f);
	dist[1] = 0;
	q.push(1); int node;
    while (!q.empty()){
  		node = q.front();
  		q.pop();
  		for (pii x: adj[node]){
  			int newcost = x.second + dist[node];
  			if (newcost < dist[x.first]){
  				dist[x.first] = newcost;
  				q.push(x.first);
  			}
  		}
  	}
    cout << dist[n] << endl;
	return 0;
}