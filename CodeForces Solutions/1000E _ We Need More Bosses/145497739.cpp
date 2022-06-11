#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 int n,m; cin >> n >> m;
 vector<vector<int>> adj(n+1),adj2(n+1);
 vector<int> par(n+1),siz(n+1,1),dp(n+1),lvl(n+1);
 for (int i = 0; i < m; ++i){
  int x,y; cin >> x >> y;
  adj[x].emplace_back(y);
  adj[y].emplace_back(x);
 }
 for (int i = 1; i <= n; ++i) par[i] = i;
 function<int(int)> find = [&](int node){
  return par[node] = node == par[node] ? node : find(par[node]);
 };
 function<void(int,int)> merge = [&](int a, int b){
  a = find(a); b = find(b);
  if (a == b) return;
  if (siz[a] > siz[b]) swap(a,b);
  par[a] = b;
  siz[b] += siz[a];
 };
 function<void(int,int)> dfs = [&](int u, int p){
  for (int v: adj[u]){
   if (v == p) continue;
   if (lvl[v] == 0){
    lvl[v] = lvl[u] + 1;
    dfs(v,u);
    dp[u] += dp[v];
   }
   else if (lvl[v] > lvl[u]) --dp[u];
   else if (lvl[v] < lvl[u]) ++dp[u];
  }
  if (dp[u] != 0) merge(u,p);
 };
 dfs(1,1);
 for (int u = 1; u <= n; ++u){
  for (int v: adj[u]){
   int pu = find(u), pv = find(v);
   if (pu != pv) adj2[pu].emplace_back(pv);
  }
 }
 int len = 0, far = -1;
 function<void(int,int,int)> dfs2 = [&](int u, int p, int d){
  if (d >= len){
   far = u;
   len = d;
  }
  for (int v: adj2[u]){
   if (v == p) continue;
   dfs2(v,u,d+1);
  }
 };  
 dfs2(find(1),find(1),0);
 len = 0;
 assert(far != -1);
 dfs2(far,far,0);
 cout << len << "\n";  
 return 0;
}