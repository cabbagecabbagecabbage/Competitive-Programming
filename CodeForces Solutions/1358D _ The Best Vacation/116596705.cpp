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
the optimal segment always ends at the end of a month
 
2 pointers
A points to the month where the segment starts, but doesnt necessarily start on the first day of that month
B points to the month whose end coincides with the end of a segment
 
 
we may need to subtract from month A so that the segment become exactly x long
*/
 
const int nax = 2e5 + 5;
 
int n,x,arr[nax*2];
 
inline int calc(int x){
 return (x * (x + 1)) / 2;
}
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,x);
 f(n){
  int d;
  in(d);
  arr[i] = arr[i+n] = d;
 }
 int ans = 0, a = 0, b = -1, days = 0, hugs = 0;
 while (b < 2*n-1){
  ++b; days += arr[b]; hugs += calc(arr[b]);
  while (days - arr[a] >= x){
   days -= arr[a];
   hugs -= calc(arr[a]);
   ++a;
  }
  int front = max(days - x, 0);
  ans = max(ans, hugs - calc(front));
 }
 out(ans);  
}