#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define int     long long
#define double    long double
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
inline int gcd(int a, int b){return (b == 0 ? a : gcd(b,a%b));}
inline int lcm(int a, int b){return a * b / (gcd(a,b));}
 
/*
 
*/
 
const int nax = 2e5 + 5, mod = 1e9 + 7;
int n, l[42];
 
void solve(){
 int ans = 0;
 in(n);
 f2(2,42){
  ans += ((n / l[i-1]) - (n / l[i])) % mod * i % mod;
  ans %= mod;
 }
 out(ans);
}
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 l[1] = 1;
 f2(2,42){
  l[i] = lcm(l[i-1],i);
 }
 int t; in(t);
 while (t--) solve();
 return 0;
}