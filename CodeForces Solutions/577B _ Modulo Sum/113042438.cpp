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
dp[i][j] stores whether j%m can be achieved with some subsequence of the first i numbers
*/
 
const int nax = 1e3 + 5;
int n,m,dp[nax][nax],arr[nax];
 
int32_t main() {
 in(n,m);
 f2(1,n+1) in(arr[i]), arr[i] %= m;
 if (n > m){
  out("YES");
  return 0;
 }
 dp[0][0] = 1;
 f2(1,n+1){
  ff(m+1){
   dp[i][j] = (dp[i-1][j] || dp[i-1][(j - arr[i] + m) % m]);
  }
 }
 if (dp[n][m]) out("YES");
 else out("NO");
 return 0;
}