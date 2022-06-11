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
 
const int nax = 1e3 + 5, mod = 1e9 + 7;
 
int dista(pii a, pii b){
 return abs(a.first - b.first) + abs(a.second - b.second);
}
 
void solve(){
 // out(dista({1000000000, 50}, {50, 1}) + dista({1000000000, 50}, {1, 1000000000}) + dista({50, 1}, {1, 1000000000}));
 int n,m,y,x;
 in(n,m,y,x);
 pii dirs[4] = {{0,0},{0,m-1},{n-1,0},{n-1,m-1}};
 pii start = {y-1,x-1};
 int ans = 0;
 pair<pii,pii> best;
 f(4){
  ff2(i+1,4){
   pii a = {dirs[i].first, dirs[i].second};
   pii b = {dirs[j].first, dirs[j].second};
   int dist = dista(start,a) + dista(a,b) + dista(b,start);
   if (dist > ans){
    ans = dist;
    best = {a,b};
   }
  }
 }
 // out(ans);
 out(best.first.first+1, best.first.second+1, best.second.first+1, best.second.second+1);
}
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--) solve();
 return 0;
}