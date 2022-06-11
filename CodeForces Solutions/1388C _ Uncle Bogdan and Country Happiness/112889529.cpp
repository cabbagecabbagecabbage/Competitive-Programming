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
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
the number of people who will visit a city is the number of people who live in the subtree rooted at that city cuz they all have to pass thru this city
1. number of happy people who visit this city is an integer
2. this number is in the range [0,visits[city]] (cant have more happy people than people)
3. the destination cities cannot have more happy people than the current city
 
 
*/
 
const int nax = 1e5 + 5;
int n,m,yes = 1,visits[nax],happiness[nax],happy_visits[nax];
vi adj[nax];
 
void dfs(int node, int prev){
 // cout << node << " " << prev << "\n";
 int happychildren = 0;
 for (int nex: adj[node]){
  if (nex == prev) continue;
  dfs(nex, node);
  visits[node] += visits[nex];
  happychildren += happy_visits[nex];
 }
 // out("info", visits[node], happiness[node]);
 int temp = happiness[node] + visits[node];
 happy_visits[node] = (temp / 2);
 if (temp % 2) yes = 0;
 if (happy_visits[node] > visits[node] or happy_visits[node] < 0) yes = 0;
 if (happy_visits[node] < happychildren) yes = 0;
}
 
void solve(){
 yes = 1;
 in(n,m);
 f2(1,n+1) in(visits[i]);
 f2(1,n+1) in(happiness[i]);
 f(n-1){
  int x, y;
  in(x,y);
  adj[x].eb(y);
  adj[y].eb(x);
 }
 dfs(1,0);
 if (yes) out("YES");
 else out("NO");
 
 f(n+1){
  adj[i].clear();
 }
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}