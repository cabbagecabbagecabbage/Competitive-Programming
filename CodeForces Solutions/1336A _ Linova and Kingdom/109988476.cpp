#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (decltype(a) j = 0; j < a; ++j)
#define f2(a, b) for (decltype(a) i = a; i < b; ++i)
#define ff2(a, b) for (decltype(a) j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
#define int long long
const int nax = 2e5 + 5;
vi all;
int n,k,a,b;
int desc[nax],depth[nax];
vi adj[nax];
 
void dfs(int node, int prev){
 depth[node] = depth[prev] + 1;
 for (int x: adj[node]){
  if (x == prev) continue;
  dfs(x,node);
  desc[node] += desc[x] + 1;
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
 f2(1,n+1){
  all.eb(depth[i]-1-desc[i]);
 }
 sort(all.begin(),all.end(),greater<int>());
 int s = 0;
 f(k){
  s += all[i];
 }
 out(s);
 return 0;
}