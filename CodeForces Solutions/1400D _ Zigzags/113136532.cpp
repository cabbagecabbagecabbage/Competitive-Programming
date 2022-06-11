#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
 
*/
 
const int nax = 3e3 + 5;
int n;
int arr[nax];
 
void solve(){
 in(n);
 f(n) in(arr[i]);
 int ans = 0;
 gp_hash_table<int, int> left, right;
 for (int j = 0; j < n; ++j){
  right.clear();
  for (int k = n - 1; k > j; --k){
   ans += left[arr[k]] * right[arr[j]];
   right[arr[k]]++;
  }
  left[arr[j]]++;
 }
 out(ans);
 
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}