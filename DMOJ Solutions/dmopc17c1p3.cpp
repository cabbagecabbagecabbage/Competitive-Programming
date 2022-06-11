#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
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

struct obj{
	int danger, dist, node;
	obj(int da, int di, int no){
		danger = da;
		dist = di;
		node = no;
	}
	bool operator < (const obj &other) const {
		if (danger == other.danger){
			return dist > other.dist;
		}
		return danger > other.danger;
	}
};

int n, m;
vector<pii> adj[100005];
priority_queue<obj> q;
int visited[100005];


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	f(m){
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].pb(mp(b,t));
		adj[b].pb(mp(a,t));
	}
	
	q.push(obj(0,0,1)); //dangerous, 
	while (!q.empty()){
		visited[q.top().node] = 1;
		if (q.top().node==n){
			cout << q.top().danger << " " << q.top().dist << endl;
			return 0; 
		}
		for (pii p: adj[q.top().node]){
			if (!visited[p.first]){

				q.push(obj(q.top().danger+p.second,q.top().dist+1,p.first));
			}
		}
		q.pop();
	}
	cout << -1 << endl;
	return 0;
}




















//trailing lines ftw