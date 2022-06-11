#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define int long long
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const int nax = 1e3 + 5;
int t;
int n, x, dist[nax];
vi adj[nax];
 
void solve(){
 in(n,x);
 int a,b;
 f2(1,n+1) adj[i].clear();
 f(n-1){
  in(a,b);
  adj[a].eb(b);
  adj[b].eb(a);
 }
 if (adj[x].size() <= 1){
  out("Ayush");
  return;
 }
 int remaining = n - 1 - 2;
 // out(remaining, adj[x].size());
 if (remaining % 2){
  out("Ayush");
 }
 else out("Ashish");
}
   
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while (t--){
  solve();
 }
   
 
 return 0;
}