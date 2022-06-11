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
// #define int     long long
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
 
/*
 
*/
 
const int nax = 1e0 + 5;
int n,k,r;
 
int32_t main() {
 // ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--){
  in(n,k);
  cout << 0 << "\n";
  in(r);
  if (r) continue;
  f2(1,n){
   cout << ((i-1) ^ (i)) << "\n";
   in(r);
   if (r) break;
  }
 }
 
 return 0;
}