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

int visited[30001];
vi adj[30001];
int n,k,m;
queue<pii> q; //(depth,node)

int main() {
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a,b;
    f(m){
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    cin >> k;
   	int office;
    f(k){
    	cin >> office;
    	// visited[office] = 1;
    	q.push(mp(0,office));
    }
    pii node;int ans = 0;
    while (!q.empty()){
    	node = q.front();
    	// cout << node.first << " " << node.second << " ";
    	q.pop();
    	if (!visited[node.second]){
    		visited[node.second] = 1;
    		ans = max(ans,node.first);
    		for (int x: adj[node.second]){
    			if (!visited[x]){
    				q.push(mp(node.first+1,x));
    			}
    		}
    	}
    }
    // cout << endl;
    cout << ans << endl;
 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}