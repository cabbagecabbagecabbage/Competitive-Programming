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
 
*/
const int nax = 2e5 + 5, mod = 1e9 + 7;
 
struct Matrix{
 int M[4][4] = {};
 Matrix operator* (const Matrix& other) const{
  Matrix ret;
  for (int i = 0; i < 4; ++i){
   for (int j = 0; j < 4; ++j){
    for (int k = 0; k < 4; ++k){
     ret.M[i][k] = (ret.M[i][k] + M[i][j] * other.M[j][k]) % mod;
    }
   }
  }
  return ret;
 }
};
 
 
 
Matrix binpow(Matrix self, int p){
 Matrix ret; f(4) ret.M[i][i] = 1;
 while (p > 0){
  if (p % 2){
   ret = self * ret;
  }
  self = self * self;
  p /= 2;
 }
 return ret;
}
 
int32_t main() {
 int n;
 in(n);
 Matrix ans;
 f(4) ff(4) ans.M[i][j] = 1; f(4) ans.M[i][i] = 0;
 ans = binpow(ans,n);
 // f(4){
  // ff(4){
   // cout << ans.M[i][j] << " ";
  // }
  // cout << "\n";
 // }
 out(ans.M[2][2]);
 
 return 0;
}