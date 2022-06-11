#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
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
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const int nax = 2e5 + 5;
int t;
int toint(string s){
 int l = s.length();
 int ret = 0, cnt = 0;
 for (int i = l - 1; i > -1; ++i){
  ret += (s[i] - '0') * pow(10,(cnt++));
 }
 return ret;
}
 
void solve(){
 string s;
 int num, cap;
 in(s,cap);
 num = stoll(s);
 int len = s.length(), sum = 0, total = 0;
 int final = 0; bool ok = false;
 f(len){
  int dig = s[i] - '0'; total += dig;
  if (ok){
   final *= 10;
   continue;
  }
  if (sum + dig + 1 > cap){
 
   final += 1;
   ok = true;
   final *= 10;
   continue;
  }
  final *= 10;
  final += dig;
  sum += dig;
 }
 if (total <= cap) out(0);
 else out(final - num);
}
   
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 cout << fixed << setprecision(0);
 in(t);
 while (t--){
  solve();
 }
   
 
 return 0;
}