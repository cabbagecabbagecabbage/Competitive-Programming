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
 
#define int    long long
#define f(a)    for (int i = 0; i < a; ++i)
#define ff(a)    for (int j = 0; j < a; ++j)
#define f2(a, b)   for (int i = a; i < b; ++i)
#define ff2(a, b)   for (int j = a; j < b; ++j)
#define mem(a, b)   fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define min(a, b)   ((a) < (b) ? (a) : (b))
#define max(a, b)   ((a) > (b) ? (a) : (b))
#define inf    0x3f3f3f3f
#define llinf    0x3f3f3f3f3f3f3f3f
#define eb     emplace_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const int nax = 5e3 + 5;
int n;
int arr[nax];
 
 
int solve(int l, int r, int h){
 // out(l,r);
 if (l == r) return 1;
 int smal = llinf;
 f2(l,r+1) smal = min(smal, arr[i] - h);
 int start = l, ret = smal;
 f2(l,r+1){
  if (arr[i] - h == smal){
   if (i != start) ret += solve(start, i - 1, h + smal);
   start = i + 1;
  }
 }
 if (arr[r] - h != smal) ret += solve(start, r, h + smal);
 return min(ret, r - l + 1);
}
 
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n);
 f(n){
  in(arr[i]);
 }
 out(solve(0,n-1,0));
 
 
 return 0;
}