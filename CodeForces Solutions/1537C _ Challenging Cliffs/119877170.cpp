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
 
const int nax = 2e5 + 5, mod = 1e9 + 7;
int n, ans[nax];
bool aput[nax];
vi h;
 
void solve(){
 in(n);
 f(n){
  int a;
  in(a);
  h.eb(a);
 }
 sort(h.begin(), h.end());
 int mindiff = llinf, ind; pii nums;
 vi possible;
 for (int i = n-2; i > -1; --i){
  if (h[i+1] - h[i] < mindiff){
   mindiff = h[i+1] - h[i];
   ind = i;
  }
 }
 ans[0] = h[ind];
 ans[n-1] = h[ind+1];
 h.erase(h.begin() + ind);
 h.erase(h.begin() + ind);
 int ptr = 1;
 f(n-2){
  if (h[i] >= ans[ptr-1]){
   ans[ptr++] = h[i];
   aput[i] = true;
  }
 }
 f(n-2){
  if (!aput[i]){
   ans[ptr++] = h[i];
   aput[i] = true;
  }
 }
 f(n){
  cout << ans[i] << " ";
  aput[i] = false;
 }
 out("");
 h.clear();
}
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--) solve();
 return 0;
}