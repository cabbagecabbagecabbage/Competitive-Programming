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
#define int long long
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
difference array O(1) updates
calc the actual array, push back (#number of accesses, index) into vector
sort the array
sort the values
match up
multiply
win
*/
 
const int nax = 2e5 + 5;
 
int n,q,arr[nax],diff[nax],s[nax],l,r,ans = 0;
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,q);
 f2(1,n+1) in(arr[i]);
 sort(arr+1, arr+n+1);
 f(q){
  in(l,r);
  diff[l]++;
  diff[r+1]--;
 }
 f2(1,n+1){
  s[i] = diff[i] + s[i-1];
 }
 sort(s+1,s+n+1);
 f2(1,n+1){
  ans += s[i] * arr[i];
 }
 out(ans);
 
 return 0;
}