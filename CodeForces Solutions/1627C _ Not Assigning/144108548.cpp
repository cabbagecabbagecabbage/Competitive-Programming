#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 5;
int n, ans[maxn];
vector<pair<int,int>> adj[maxn];
 
void dfs(int u, int p, int prime){
 for (pair<int,int> v: adj[u]){
  if (v.first == p) continue;
  int otherprime = (prime == 3 ? 2 : 3);
  ans[v.second] = otherprime;
  dfs(v.first,u,otherprime);
 }
}
 
void solve(){
 cin >> n;
 for (int i = 0; i < n-1; ++i){
  int u,v; cin >> u >> v;
  adj[u].emplace_back(v,i);
  adj[v].emplace_back(u,i);
 }
 for (int i = 1; i <= n; ++i){
  if (adj[i].size() > 2){
   cout << -1 << "\n";
   for (int j = 1; j <= n; ++j){
    adj[j].clear();
   }
   return;
  }
 }
 int start = -1;
 for (int i = 1; i <= n; ++i){
  if (adj[i].size() == 1){
   start = i;
   break;
  }
 }
 assert(start != -1);
 dfs(start, start, 2);
 for (int i = 0; i < n-1; ++i){
  cout << ans[i] << " ";
 }
 cout << "\n";
 for (int i = 1; i <= n; ++i){
  adj[i].clear();
 }
}
 
int32_t main(){
 int t; cin >> t;
 while (t--) solve();
 return 0;
}