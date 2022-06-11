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
if there are n bacterias then the growth rate is n
the growth rate can double by splitting every bacteria, or can stay the same by not splitting
growth rate -> increase by [0,n]
 
greedy: grow as fast as possible toward n
 
if every bacteria always split:
1 + (2 + 4 + 8
 
if we dont split then growth rate doesnt change
sample n = 9
1 + 2 + 2 + 4
 
sample n = 11
1 + 2 + 3 + 5
 
keep doubling until right before we exceed n. then insert the difference in the sequence
 
*/
 
const int nax = 3e3 + 5;
int n;
multiset<int> arr;
 
void solve(){
 arr.clear();
 in(n);
 int s = 0, num, days = 0;
 f(33){
  s += (1ll << i);
  arr.insert(1ll << i);
  if (s == n){
   days = i;
   break;
  }
  if (s > n){
   s -= (1ll << i);
   arr.erase(1ll << i);
   arr.insert(n - s);
   days = i;
   break;
  }
 }
 out(days);
 vi lis;
 for (int x: arr){
  lis.eb(x);
  // out(x);
  if (days-- == 0) break;
 }
 f2(1,(int) lis.size()) cout << lis[i] - lis[i-1] << " ";
 cout << "\n";
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 // f(33) arr.insert((1ll << i));
 
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}