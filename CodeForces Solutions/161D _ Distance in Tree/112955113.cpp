#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
 
#define int    long long
#define f(a)    for (int i = 0; i < a; ++i)
#define ff(a)    for (int j = 0; j < a; ++j)
#define f2(a, b)   for (int i = a; i < b; ++i)
#define ff2(a, b)   for (int j = a; j < b; ++j)
#define mem(a, b)   fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define min(a, b)   ((a) < (b) ? (a) : (b))
#define max(a, b)   ((a) > (b) ? (a) : (b))
#define inf    0x3f3f3f3f
#define llinf    0x3f3f3f3f3f3f3f3f
#define eb     emplace_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
down[node][i] - number of paths starting from node of length i that goes down into its subtree
all[node][i] - number of paths starting from node of length i (going in all directions)
 
all[node][i] = down[node][i] + all[parent[node]][i-1] - down[node][(i-1)-1]
Explanation: We want to also find the paths that go up, so first we calculate the number of paths of length i-1 (since the distance between parent and node is 1) from the parent. but this also includes going down, which is already counted in down[node][i], so we need to subtract the ones that go down. 
*/
 
const int nax = 5e4 + 5;
int n,k,a,b,ans = 0,down[nax][505],all[nax][505];
vi adj[nax];
 
void dfs(int node, int pre){
 all[node][0] = down[node][0] = 1;
 for (int x: adj[node]){
  if (x == pre) continue;
  dfs(x, node);
  f(k) down[node][i+1] += down[x][i], all[node][i+1] += down[x][i];
 }
}
 
void dfs2(int node, int pre){
 if (node != 1){
  all[node][1] += all[pre][0];
  f2(2,k+1) all[node][i] += (all[pre][i-1] - down[node][i-2]);
 }
 ans += all[node][k];
 for (int x: adj[node]){
  if (x == pre) continue;
  dfs2(x, node);
 }
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,k);
 f(n-1){
  in(a,b);
  adj[a].eb(b);
  adj[b].eb(a);
 }
 dfs(1,0);
 dfs2(1,0);
 out(ans / 2);
 return 0;
}