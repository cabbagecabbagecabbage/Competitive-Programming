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
 
const int nax = 2e3 + 5;
int arr[nax], n, dp[nax][nax];
 
int32_t main() {
 in(n);
 f(n) in(arr[i]);
 sort(arr, arr + n);
 int ans = LLONG_MAX;
 dp[0][n-1] = 0;
 for (int i = 0; i < n; ++i){
  for (int j = n-1; j >= i; --j){
   int a = llinf, b = llinf;
   if (i != 0 or j != n-1){
    if (i){
     a = dp[i-1][j] + arr[j] - arr[i-1];
    }
    if (j < n-1){
     b = dp[i][j+1] + arr[j+1] - arr[i];
    }
    dp[i][j] = min(a,b);
   }
  }
 }
 f(n) ans = min(ans, dp[i][i]);  
 out(ans);
}