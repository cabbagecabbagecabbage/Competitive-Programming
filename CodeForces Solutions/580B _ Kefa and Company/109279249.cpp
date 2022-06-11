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
sort by amount of money
for each distinct amount of money m, calculate the sum of friendship factors whose money is in the range [m,m+d]
use prefix sums
use binary search to find the largest index in the array whose money is strictly smaller than m
then again find the largest index in the array whose money is strictly smaller than m+d
*/
#define int long long
const int nax = 1e5 + 5;
 
vector<pii> friends;
unordered_set<int> check;
int pref[nax];
int n, d, m, s;
 
int bsearch(int upperbound){
 int lo = 0, hi = n, ans = 0;
 while (hi >= lo){
  int mid = (lo + hi) / 2;
  if (friends[mid].first < upperbound){
   ans = max(ans,mid);
   lo = mid + 1;
  }
  else{
   hi = mid - 1;
  }
 }
 // out(ans,upperbound);
 return ans;
}
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 cin >> n >> d;
 f(n){
  cin >> m >> s;
  friends.emplace_back(m,s);
  check.insert(m);
 }
 friends.emplace_back(0,0);
 sort(friends.begin(), friends.end());
 f2(1,n+2){
  pref[i] = pref[i-1] + friends[i-1].second;
  // cout << friends[i-1].second << " ";
 }
 // cout << endl;
 // f(n+2) cout << pref[i] << " ";
 // cout << endl;
 int ans = 0;
 for (int left: check){
  int right = left + d; //strictly smaller bsearch so dont have to subtract
  int l = bsearch(left);
  int r = bsearch(right);
  // out(l,r,pref[r+1] - pref[l+1]);
  ans = max(ans, pref[r+1] - pref[l+1]);
 }
 out(ans);
 
 return 0;
}