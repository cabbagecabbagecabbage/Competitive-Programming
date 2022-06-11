// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") //can cause RTE on some sites
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <ext/pb_ds/tree_policy.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define int     long long
#define f(a)     for (int i = 0; i < a; ++i)
#define ff(a)     for (int j = 0; j < a; ++j)
#define f2(a, b)    for (int i = a; i < b; ++i)
#define ff2(a, b)    for (int j = a; j < b; ++j)
#define fil(arr, val) fill((remove_array<decltype(arr)>::type*)&arr, (remove_array<decltype(arr)>::type*)((char*)&arr + sizeof(arr)), val)
template<typename T> struct remove_array {typedef T type;};
template<typename T, size_t sz> struct remove_array<T[sz]> { typedef typename remove_array<T>::type type;};
#define mem(a, b)   memset(a, b, sizeof(a))
#define min(a, b)    ((a) < (b) ? (a) : (b))
#define max(a, b)    ((a) > (b) ? (a) : (b))
#define outs(a)    cout << a << " "
#define nl()    cout << "\n"
#define inf     0x3f3f3f3f
#define llinf     0x3f3f3f3f3f3f3f3f
#define eb      emplace_back
typedef vector<int>   vi;
typedef pair<int, int>   pii;
typedef vector<pair<int,int>> vpii;
inline int gcd(int a, int b){return (b == 0 ? a : gcd(b,a%b));}
inline int lcm(int a, int b){return a * b / (gcd(a,b));}
 
/*
dp[i][j] number of subsequences in the prefix of length i with j elements smaller than a given x
*/
 
const int nax = 5e2 + 5, mod = 1e9 + 7, mod2 = 998244353;
int n, dp[nax][nax],arr[nax];
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n);
 f2(1,n+1){
  char op; in(op);
  if (op == '-'){
   arr[i] = -1;
  }
  else in(arr[i]);
 }
 int ans = 0;
 for (int k = 1; k <= n; ++k){
  if (arr[k] == -1) continue;
  mem(dp,0);
  dp[0][0] = 1;
  f2(1,n+1){
   ff(n){
    //take arr[i] in the subsequence
    //if arr[i] is -1
    if (arr[i] == -1){
     if (i <= k or j) dp[i][max(0,j-1)] += dp[i-1][j], dp[i][max(0,j-1)] %= mod2;
     //i > k and j = 0 means the arr[k] is removed; cant continue from this subsequence
    }
    //if smaller or useful 
    else {
     if (arr[i] < arr[k] or (arr[i] == arr[k] and i < k)){
      dp[i][j] += dp[i-1][j-1], dp[i][j] %= mod2;
     }
     //if bigger
     else {
      dp[i][j] += dp[i-1][j], dp[i][j] %= mod2;
     }
    }
    
    //dont take
    if (i != k){
     dp[i][j] += dp[i-1][j], dp[i][j] %= mod2;
    }
   }
  }
  int t = 0;
  f(n+1) t = (t + dp[n][i]) % mod2;
  ans = (ans + t * arr[k] % mod2) % mod2;
 }
 out(ans);
        
 
 return 0;
}