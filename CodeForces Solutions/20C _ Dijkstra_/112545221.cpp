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
 
*/
 
const int nax = 1e5 + 5;
 
int n,m,a,b,w;
vector<pii> adj[nax];
int dist[nax], from[nax];
priority_queue<pii, vector<pii>, greater<pii>> pq;
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,m);
 f(m){
  in(a,b,w);
  adj[a].eb(b,w);
  adj[b].eb(a,w);
 }
 mem(dist,llinf);
 dist[1] = 0;
 pq.emplace(0,1);
 while (!pq.empty()){
  int cost, node;
  tie(cost, node) = pq.top(); pq.pop();
  if (dist[node] != cost) continue;
  for (pii k: adj[node]){
   int next, weight;
   tie(next, weight) = k;
   if (weight + dist[node] < dist[next]){
    from[next] = node;
    dist[next] = dist[node] + weight;
    pq.emplace(dist[next],next);
   }
  }
 }
 if (dist[n] == llinf){
  out(-1);
  return 0;
 }
 
 vi ans;
 for (int i = n; i != 0; i = from[i]){
  ans.eb(i);
 }
 for (int i = ans.size() - 1; i > -1; i--) cout << ans[i] << " "; cout << endl;
  
 
 return 0;
}