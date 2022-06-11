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

int visited[1001];
vi adj[1001];
int n;
int cycle = 0;

void dfs(int node){
	visited[node] = 1;
	for (int x: adj[node]){
		if (visited[x]==1){
			cycle = 1;
			return;
		}
		if (visited[x]==0) dfs(x);
	}
	visited[node] = 2;
}

int main() {
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    f(n){
    	ff(n){
    		int val;
    		cin >> val;
    		if (val){
    			adj[i].push_back(j);
    		}
    	}
    }

    f(n){
    	if (visited[i] == 0){
    		dfs(i);
    		visited[i] = 1;
    	}
    	if (cycle){
    		cout << "NO" << endl;
    		return 0;
    	}
    }
    cout << "YES" << endl;

 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}