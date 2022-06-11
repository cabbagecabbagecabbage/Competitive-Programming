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
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;


/*
MST problem
do a kruskals
first sort the edges
safe wires come first and if 2 edges are the same then compare costs
*/

struct Edge{
	int cost,a,b,d;
	Edge(int a1, int b1, int c1, int d1){
		a = a1;
		b = b1;
		cost = c1;
		d = d1;
	}
};

vector<Edge> edges;
int parent[101];
int n,m;

int sfind(int v){
	if (parent[v]==v) return v;
	return parent[v] = sfind(parent[v]);
}

void sunion(int a, int b){
	parent[sfind(a)] = sfind(b);
}

bool compare(Edge e1, Edge e2){
	if (e1.d and !e2.d) return false;
	if (e2.d and !e1.d) return true;
	return e1.cost < e2.cost;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a,b,c,d;
    f(m){
    	cin >> a >> b >> c >> d;
    	edges.pb(Edge(a,b,c,d));
    }
    sort(edges.begin(),edges.end(), compare);
    f(n+1) parent[i] = i;
    // f(m){
    	// cout << edges[i].a << edges[i].b << edges[i].cost << edges[i].d << endl;
    // }
    int ans = 0, dangerous = 0;
    f(m){
    	if (sfind(edges[i].a) != sfind(edges[i].b)){
    		sunion(edges[i].a,edges[i].b);
    		// cout << a << " " << b << endl;
    		dangerous += edges[i].d;
    		ans += edges[i].cost;	
    	}
    }

	cout << dangerous << " " << ans << endl;
	return 0;
}