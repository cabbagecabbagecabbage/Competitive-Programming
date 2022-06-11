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
ACTUALLY LOOKING FOR THE KTH SMALLEST NUMBER BREEEH
*/
 
const int nax = 1e5 + 5;
int n,m,k;
 
 
int lessthan(int x){
 int ret = 0;
 f2(1,n+1){
  ret += min(m, (x - 1) / i);
 }
 return ret;
}
 
 
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,m,k);
 int lo = 1, hi = n * m;
 int ans = -1;
 while (hi >= lo){
  int mid = (lo + hi) / 2;
  if (lessthan(mid) < k){
   lo = mid + 1;
   ans = mid;
  }
  else{
   hi = mid - 1;
  }
 }
 out(ans);
 
 return 0;
}