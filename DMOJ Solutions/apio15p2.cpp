#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << el
#define out2(a, b) cout << a << " " << b << el
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
#define el "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*
skyscrapers as nodes
go from the skyscraper of the 1st doge to the skyscraper of the 2nd doge (i mean 0 and 1)
edges: for each doge in the skyscraper, try to make every jump possible, even more than 1 jump


ok i TLE ed so i looked a solution
observation: if the location that you are going to has a doge that has the same p value as the currently processing p value (doge), then you need not jump further because the doge at the location can jump further than you can!
*/

const int nax = 3e4 + 5;

int n,m,b,p,s,e;
unordered_set<int> doges[nax];
priority_queue<pii,vector<pii>,greater<pii>> q;
int dist[nax];


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	in2(b,p);
	s = b;
	doges[b].insert(p);
	in2(b,p);
	e = b;
	doges[b].insert(p);
	f2(2,m){
		in2(b,p);
		doges[b].insert(p);
	}
	
	mem(dist,infb);
	dist[s] = 0;
	q.emplace(0,s);
	int cost, node, newcost, location;
	while (!q.empty()){
		tie(cost, node) = q.top(); q.pop();
		if (node == e){
			out(cost);
			return 0;
		}
		if (cost != dist[node]) continue;
		for (int doge: doges[node]){
			for (int jumps = 1; (location = node + jumps*doge) <= n-1; jumps++){ //try defining location here
				newcost = cost + jumps;
				if (newcost < dist[location]){
					q.emplace(newcost,location);
					dist[location] = newcost;
				}
				if (doges[location].count(doge)) break;
			}
			for (int jumps = 1; (location = node - jumps*doge) >= 0; jumps++){
				newcost = cost + jumps;
				if (newcost < dist[location]){
					q.emplace(newcost,location);
					dist[location] = newcost;
				}
				if (doges[location].count(doge)) break;
			}
		}
	}
		
	out(-1);


	return 0;
}




















//trailing lines ftw