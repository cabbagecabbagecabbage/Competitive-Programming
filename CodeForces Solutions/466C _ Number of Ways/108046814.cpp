#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (decltype(a) i = 0; i < a; ++i)
#define ff(a) for (decltype(a) j = 0; j < a; ++j)
#define f2(a, b) for (decltype(a) i = a; i < b; ++i)
#define ff2(a, b) for (decltype(a) j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const ll nax = 5e5 + 5;
ll cnt[nax],arr[nax],suf[nax],n;
 
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n);
 ll total = 0;
 f(n) in(arr[i]), total += arr[i];
 if (total % 3 != 0){
  out(0);
  return 0;
 }
 ll sufs = 0, third = total / 3;
 for (int i = n-1; i >= 0; --i){
  sufs += arr[i];
  if (sufs == third) cnt[i] = 1;
  suf[i] = suf[i+1] + cnt[i];
 }
 ll ans = 0, pref = 0;
 for (int i = 0; i < n; ++i){
  pref += arr[i];
  if (pref == third){
   ans += suf[i+2];
  }
 }
 out(ans);
  
 
 return 0;
}