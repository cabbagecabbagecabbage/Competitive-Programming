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
const int nax = 505;
vector<pair<int,double>> adj[nax];
unordered_map<string,int> fruitnum;

int n,m;
string f,a,b;
double c, dist[nax];
queue<int> q; //current fruit

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	string ap = "APPLES";
	int apple, count = 0;
	f(n){
		in(f);
		if (f==ap) apple = count;
		fruitnum[f] = count++;
	}
	f(m){
		in3(a,b,c);
		adj[fruitnum[a]].eb(fruitnum[b],c);
	}
	q.push(apple);
	dist[apple] = 1;
	int node; double newcost;
	while (!q.empty()){
		node = q.front(); q.pop();
		for (pair<int,double> x: adj[node]){
			newcost = round(dist[node] * x.second * 10000000000) / 10000000000;
			if (newcost > dist[x.first]){
				if (x.first == apple){
					out("YA");
					return 0;
				}
				dist[x.first] = newcost;
				q.push(x.first);
			}
		}
	}
	// f(n) out(dist[i]);
	out("NAW");
	return 0;
}




















//trailing lines ftw