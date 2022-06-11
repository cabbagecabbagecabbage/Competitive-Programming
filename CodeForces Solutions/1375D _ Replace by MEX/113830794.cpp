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
dp[i][j] stores the minimum unpleasant value for the first i dishes using j minutes
dp[i][j] = min(dp[i-1][j-1] + abs(arr[i] - j), dp[i][j-1])
*/
 
const int nax = 1e3 + 5;
int n, arr[nax], output[2 * nax];
void solve(){
 unordered_set<int> unprocessed;
 multiset<int> all;
 in(n);
 f(n){
  in(arr[i]);
  if (arr[i] != i){
   unprocessed.insert(i);
   // out("inserted:",i);
  }
  all.insert(arr[i]);
 }
 // for (int i: all) cout << i << " "; cout << "\n";
 int cnt = 0;
 while (!unprocessed.empty()){
  //find mex
  int nex = 0;
  for (auto i = all.begin(); i != all.end(); ++i){
   // out("i:", *i, "nex", nex);
   if (*i > nex){
    break;
   }
   else nex = *i + 1;
  }
  // out("nex:", nex);
  if (nex == n){
   int idx = *unprocessed.begin();
   all.erase(all.find(arr[idx]));
   all.insert(nex);
   arr[idx] = nex;
   output[cnt] = idx;
  }
  else{
   all.erase(all.find(arr[nex]));
   all.insert(nex);
   arr[nex] = nex;
   unprocessed.erase(nex);
   output[cnt] = nex;
  }
  cnt++;
  // f(n) cout << arr[i] << " ";
  // cout << "\n";
  
 }
 out(cnt);
 if (cnt){
  f(cnt){
   cout << output[i] + 1 << " ";
  }
  cout << "\n";
 }
 // out("");
 
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}