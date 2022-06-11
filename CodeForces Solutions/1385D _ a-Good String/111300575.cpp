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
 
const int nax = (1 << 17) + 5;
// char alpha[27] = "abcdefghijklmnopqrstuvwxyz";
char s[nax];
 
int cnt(int start, int end, char c){
 int ret = 0;
 f2(start, end + 1) ret += s[i] == c;
 return ret;
}
 
int rs(char idx, int left, int right){
 if (left == right){
  return (idx != s[left]);
 }
 int mid = (left + right) >> 1, half = (right - left + 1) >> 1;
 
 int repleft = half - cnt(left, mid, idx);
 int repright = half - cnt(mid + 1, right, idx);
 
 return min(rs(idx + 1, left, mid) + repright,
    rs(idx + 1, mid + 1, right) + repleft);  
}
 
 
void solve(){
 int n;
 in(n,s);
 out(rs('a',0,n-1));
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--){
  solve();
 }
 return 0;
}