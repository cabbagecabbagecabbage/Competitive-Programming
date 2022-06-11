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
 
/*
 
 
*/
 
const int nax = 2e5 + 5, mod = 1e9 + 7;
const double eps = 1e-9;
double v;
 
double rsolve(double c, double m, double p, int moves){
 // out(c,m,p,curprob,moves,moves*p);
 double ret = 0;
 ret += (double) moves * p;
 if (c != 0){
  if (c <= v + eps){
   if (m == 0){
    ret += c*rsolve(0,0,1,moves+1);
   }
   else {
    ret += c*rsolve(0,m+c/2,p+c/2,moves+1);
   }
  }
  else{
   if (m == 0){
    ret += c*rsolve(c-v,0,p+v, moves+1);
   }
   else {
    ret += c*rsolve(c-v,m+v/2, p+v/2,moves+1);
   }
  }
 }
 if (m != 0){
  if (m <= v + eps){
   if (c == 0){
    ret += m*rsolve(0,0,1, moves+1);
   }
   else {
    ret += m*rsolve(c+m/2,0,p+m/2,moves+1);
   }
  }
  else{
   if (c == 0){
    ret += m*rsolve(0,m-v,p+v,moves+1);
   }
   else {
    ret += m*rsolve(c+v/2,m-v, p+v/2,moves+1);
   }
  }
 }
 return ret;
}
 
void solve(){
 double c,m,p;
 in(c,m,p,v);
 cout << fixed << setprecision(20) << rsolve(c,m,p,1) << "\n";
}
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--) solve();
 return 0;
}