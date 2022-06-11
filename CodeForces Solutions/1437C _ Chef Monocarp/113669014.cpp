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
dp[i][j] stores the minimum unpleasant value for the first i dishes using j minutes
dp[i][j] = min(dp[i-1][j-1] + abs(arr[i] - j), dp[i][j-1])
*/
 
const int nax = 2e2 + 5;
int n, dp[nax][nax*2], arr[nax];
void solve(){
 in(n);
 f2(1,n+1) in(arr[i]);
 sort(arr + 1, arr + n + 1);
 memset(dp, inf, sizeof(dp));
 f(n*2 + 1) dp[0][i] = 0;
 f2(1,n+1){
  // cout << i << " ";
  ff(n*2+1){
   if (j > 0){
    // out(i,j);
    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(arr[i] - j));
    dp[i][j] = min(dp[i][j], dp[i][j-1]);
   }
   // cout << ((dp[i][j] == llinf) ? -1 : dp[i][j]) << " ";
  }
  // cout << "\n";
 }
 // int ans = llinf;
 // f(2*n+1) ans = min(ans, dp[n][i]);
 out(dp[n][2*n]);
 
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}