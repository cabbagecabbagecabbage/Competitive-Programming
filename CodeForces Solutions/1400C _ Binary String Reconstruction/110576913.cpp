#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define int long long
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const int nax = 1e5 + 5;
string s;
int t,x;
int ans[nax];
 
 
void solve(){
 in(s,x);
 mem(ans,1);
 int l = s.length();
 f(l){
  if (s[i] == '0'){
   if (i + x < l){
    ans[i+x] = 0;
   }
   if (i - x >= 0){
    ans[i-x] = 0;
   }
   // out(ans[i-x],ans[i+x]);
  }
 }
 f(l){
  int temp = 0;
  if (i + x < l){
   temp = max(temp,ans[i+x]);
  }
  if (i - x >= 0){
   temp = max(temp,ans[i-x]);
  }
  // out(temp,s[i]-'0');
  if (temp != (int) (s[i]-'0')){
   out(-1);
   return;
  }
 }
 f(l) cout << ans[i]; out("");
}
   
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while (t--){
  solve();
 }
   
 
 return 0;
}