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
typedef pair<long long, int> pii;


/*
dijkstra? idk
looks like high const fact
*/

const int nax = 1e6+5;
int n,c,k;
vector<int> studentsinclass[nax], classesofstudent[nax];
#define sic studentsinclass
#define cos classesofstudent
ll val[nax], dist[nax];



ll go(int a, int b) {return abs(val[a] - val[b]) + k;}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in3(n,c,k);
	f2(1,n+1) in(val[i]);
	int num, clas;
	f2(1,n+1){
		in(num);
		ff(num){
			in(clas);
			sic[clas].pb(i);
			cos[i].pb(clas);
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,1});
	mem(dist,infb);
	dist[1] = 0;
	int node; ll cost;
	while (!q.empty()){
		tie(cost,node) = q.top(); q.pop();
		if (cost != dist[node]) continue;
		for (int adjclas: cos[node]){
			for (int adjstud: sic[adjclas]){
				ll newcost = go(adjstud,node) + cost;
				if (newcost < dist[adjstud]){
					dist[adjstud] = newcost;
					q.push({newcost,adjstud});
				}
			}
		}
	}
	f2(1,n+1){
		out((dist[i] == 0x3f3f3f3f3f3f3f3f ? -1 : dist[i]));
	}
	



	return 0;
}




















//trailing lines ftw