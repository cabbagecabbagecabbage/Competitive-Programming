#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define int     long long
#define f(a)     for (int i = 0; i < a; ++i)
#define ff(a)     for (int j = 0; j < a; ++j)
#define f2(a, b)    for (int i = a; i < b; ++i)
#define ff2(a, b)    for (int j = a; j < b; ++j)
#define fil(a, b)    fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define mem(a, b)   memset(a, b, sizeof(a))
#define min(a, b)    ((a) < (b) ? (a) : (b))
#define max(a, b)    ((a) > (b) ? (a) : (b))
#define inf     0x3f3f3f3f
#define llinf     0x3f3f3f3f3f3f3f3f
#define eb      emplace_back
typedef long long    ll;
typedef vector<int>   vi;
typedef pair<int, int>   pii;
 
/*
 
*/
 
const int nax = 1e5 + 5, mod = 1e9 + 7;
int n,m,size[nax];
vi paths, adj[nax];
deque<int> nums;
void dfs(int node, int par){
 size[node] = 1;
 for (int x: adj[node]){
  if (x == par) continue;
  dfs(x,node);
  paths.eb((size[x]*(n-size[x])));
  size[node] += size[x];
 }
}
 
void solve(){
 in(n);
 f(n-1){
  int u,v;
  in(u,v);
  adj[u].eb(v);
  adj[v].eb(u);
 }
 dfs(1,0); sort(paths.begin(),paths.end()); reverse(paths.begin(),paths.end());
 in(m);
 f(m){
  int x;
  in(x);
  nums.eb(x);
 }
 sort(nums.begin(),nums.end());
 reverse(nums.begin(),nums.end());
 if (m > n-1){
  f(m-(n-1)){
   nums[1] *= nums[0];
   nums[1] %= mod;
   nums.pop_front();
  }
 }
 else if (m < n-1){
  f((n-1)-m){
   nums.eb(1);
  }
 }
 
 int ans = 0;
 f(n-1) ans += (paths[i]*nums[i]) % mod, ans %= mod;
 out(ans);
 paths.clear();
 nums.clear();
 f2(1,n+1) adj[i].clear();
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--) solve();
 return 0;
}