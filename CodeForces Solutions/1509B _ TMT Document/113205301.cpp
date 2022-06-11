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
 
const int nax = 1e5 + 5;
int n, Tpre[nax], Mpre[nax], Tsuf[nax], Msuf[nax];
 
void solve(){
 in(n);
 string s;
 in(s);
 int tc = 0, mc = 0;
 f(n) tc += (s[i] == 'T'), mc += (s[i] == 'M');
 if (tc !=  2 * mc){
  out("NO");
  return;
 }
 Tpre[0] = (s[0] == 'T');
 Mpre[0] = (s[0] == 'M');
 f2(1,n){
  Tpre[i] = Tpre[i-1] + (s[i] == 'T');
  Mpre[i] = Mpre[i-1] + (s[i] == 'M');
 }
 Tsuf[n-1] = (s[n-1] == 'T');
 Msuf[n-1] = (s[n-1] == 'M');
 for (int i = n-2; i > -1; --i){
  Tsuf[i] = Tsuf[i+1] + (s[i] == 'T');
  Msuf[i] = Msuf[i+1] + (s[i] == 'M');
 }
 Tsuf[n] = 0;
 Msuf[n] = 0;
 
 f(n-1){
  if (Mpre[i] > Tpre[i] or Msuf[i+1] > Tsuf[i+1]){
   out("NO");
   return;
  }
 }
 out("YES"); 
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}