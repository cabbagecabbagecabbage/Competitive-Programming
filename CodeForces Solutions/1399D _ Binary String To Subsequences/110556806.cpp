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
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
p0 -> array of indices representing the end of a subsequence that ended with 0
p1 -> array of indices representing the end of a subsequence that ended with 1
*/
 
const int nax = 2e5 + 5;
string s;
int t,n;
vector<pii> p1, p0;
int ans[nax];
int ind;
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while(t--){
  in(n,s);
  ind = 0;
  p1.clear(); p0.clear();
  f(n){
   if (s[i] == '0'){
    if (p1.empty()){
     p0.eb(i,++ind);
     ans[i] = ind;
    }
    else {
     p0.eb(i,p1.back().second);
     ans[i] = p1.back().second;
     p1.pop_back();
    }
   }
   else if (s[i] == '1'){
    if (p0.empty()){
     p1.eb(i,++ind);
     ans[i] = ind;
    }
    else {
     p1.eb(i,p0.back().second);
     ans[i] = p0.back().second;
     p0.pop_back();
    }
   }
  }
  out(p0.size() + p1.size());
  f(n) cout << ans[i] << " "; out("");
 }
 
 
 return 0;
}