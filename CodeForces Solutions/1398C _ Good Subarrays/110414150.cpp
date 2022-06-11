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
store the difference between the prefix sum and length. map to freq
each time we reach an index, increment by the number of prefixes before it which is equal to the current length - cur prefix sum
 
cur length - prefix length = cur pref sum - prefix sum
cur length - cur pref sum = prefix length - prefix sum
*/
 
const int nax = 1e5 + 5;
int arr[nax];
int t,n,a,pref = 0;
gp_hash_table<int,int> table;
string s;
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while (t--){
  in(n,s);
  table.clear();
  f(n) arr[i] = s[i] - '0';
  table[0] = 1;
  int ans = 0, pref = 0;
  f(n){
   int l = i + 1;
   pref += arr[i];
   ans += table[l-pref];
   table[l-pref]++;
   // out(i,l-pref,ans);
  }
  out(ans);
 }
 
 
 return 0;
}