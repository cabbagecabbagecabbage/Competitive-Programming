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
 
const int nax = 2e5 + 5;
int t;
int arr[nax];
 
struct seg{
 int length, start, end;
};
 
bool c(seg f, seg s){
 if (f.length < s.length) return true;
 if ((f.length == s.length) and (f.start > s.start)) return true;
 return false;
}
 
 
void solve(){
 priority_queue<seg, vector<seg>, decltype(&c)> pq(c);
 mem(arr,0);
 int n;
 in(n);
 int num = 1;
 pq.push({n,1,n});
 while (!pq.empty()){
  seg cur = pq.top(); pq.pop();
  // out(cur.length, cur.start, cur.end);
  int mid = (cur.start + cur.end) / 2;
  arr[mid-1] = num++;
  if (mid != cur.start){
   pq.push({mid - cur.start, cur.start, mid - 1});
  }
  if (mid != cur.end){
   pq.push({cur.end - mid, mid + 1, cur.end});
  }
 }
 f(n) cout << arr[i] << " ";
 out("");
}
   
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while (t--){
  solve();
 }
   
 
 return 0;
}