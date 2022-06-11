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
first add all the lengths. if less than n then -1
 
try to start colouring the ith segment from index i. 
if we run out of space (i + length - 1 > n) then not possible
 
if possible then see how much space still needs to be covered after placing everything greedily. call this number x.
 
now we start over and instead of placing as greedily as possible, we let the segments use their full length until x runs out. (every time we use the full length, subtract length - 1 from x).
*/
 
const int nax = 1e5 + 5;
int n,m,p,arr[nax],s,l[nax];
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,m);
 f2(1,m+1){
  in(l[i]);
  s += l[i];
 }
 if (s < n){
  out(-1);
  return 0;
 }
 int maxidx = 1;
 f2(1,m+1){
  maxidx = max(maxidx, i + l[i] - 1);
 }
 if (maxidx > n){
  out(-1);
  return 0;
 }
 for (int i = m; i > 0; --i){
  arr[i] = l[i] + arr[i+1];
 }
 f2(1,m+1){
  cout << max(n - arr[i] + 1, i) << " ";
 }
 cout << "\n";
 
 return 0;
}