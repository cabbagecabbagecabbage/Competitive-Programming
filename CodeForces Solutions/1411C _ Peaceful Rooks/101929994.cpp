#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
typedef vector<int> vi;
typedef pair<int,int> pii;
 
int t,n,m;
vi adj[100001];
int visited[100001];
int ans = 0;
 
int dfs(int v, int prev){
  // cout << "vertex: " << v;n()
  visited[v] = 1;
  for (int next: adj[v]){
    if (next!=prev){
      if (visited[next]) return 1;
      // cout << "going to " << next;n()
      if (dfs(next,v)) return 1;
    }
  }
  return 0;
}
 
int main() {
  // cin.sync_with_stdio(0);
  // cin.tie(0);
  int x,y;
  cin >> t;
  f(t){
    ans = 0;
    cin >> n >> m;
    ff(n+1) adj[j].clear(),visited[j]=0;
    ff(m){
      cin >> x >> y;
      if (x!=y){
        adj[x].push_back(y);
        adj[y].push_back(x);
      } 
      else ans-=1;
    }
    ff(n){
      if (visited[j]==0 && !adj[j].empty()){
        // cout << "hi";n()
        if (dfs(j,-1)) ans+=1;
      }
    }
    cout << ans+m << "\n";
  }
    
  return 0;
}