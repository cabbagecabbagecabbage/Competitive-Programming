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

*/
const int nax = 5e5 + 5;
const int mmax = 1e6 + 5;

int n,m,q;
int x,y,z,d;
string color;

vector<pii> adj[nax];
int dist[nax], least[nax], most[nax];

void preprocess(){
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
	//minimizing brightness
	mem(dist,infb);
	mem(least,infb);
	dist[1] = least[1] = most[1] = 0;
	q.push(make_tuple(0,0,1));
	int cost, brightness, node;	
	while (!q.empty()){
		tie(cost,brightness,node) = q.top(); q.pop();
		// out2(node,brightness);
		if (least[node] != brightness || dist[node] != cost) continue;
		for (pii x: adj[node]){
			int newcost = cost + 1;
			int newbrightness = brightness + x.second;
			if (dist[x.first] > newcost || (dist[x.first] == newcost && least[x.first] > newbrightness)){
				dist[x.first] = newcost;
				least[x.first] = newbrightness;
				q.push(make_tuple(newcost,newbrightness,x.first));
			}
			
		}
	}	
	mem(most,-1);
	most[1] = 0;
	q.push(make_tuple(0,0,1));
	while (!q.empty()){
		tie(cost,brightness,node) = q.top(); q.pop();
		brightness *= -1;
		// out2(node,brightness);
		if (most[node] != brightness || dist[node] != cost) continue;
		for (pii x: adj[node]){
			int newcost = cost + 1;
			int newbrightness = brightness + x.second;
			if (dist[x.first] == newcost && most[x.first] < newbrightness){
				dist[x.first] = newcost;
				most[x.first] = newbrightness;
				q.push(make_tuple(newcost,-newbrightness,x.first));
			}
			
		}
	}	
	
}
				

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f(m){
		in3(x,y,z);
		adj[x].eb(y,z);
		adj[y].eb(x,z);
	}
	preprocess();
	in(q);
	f(q){
		in2(d,color);
		if (color[0] == 'B')
			out2(dist[d],least[d]);
		else
			out2(dist[d],most[d]);
	}



	return 0;
}




















//trailing lines ftw