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
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
vi adj[1001];
int comps = 0;
int visited[1001];
vi temp;

void dfs(int node){
	visited[node] = 1;
	temp.push_back(node);
	for (int x: adj[node]){
		if (!visited[x]) dfs(x);
	}
}

int main() {
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    int edges = 0;
    f(n){
    	ff(n){
    		int val;
    		cin >> val;
    		if (val){
                adj[i].push_back(j);
                edges++;
            }
    	}
    }
    edges /= 2;

    f(n){
    	if (!visited[i]){
    		temp.clear();
    		dfs(i);
    		comps++;
    	}
    }
    cout << edges - (n-comps) << endl;


 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}