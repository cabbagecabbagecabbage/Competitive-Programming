#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int mod = 1e9 + 7;
 
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
 Matrix ret; for (int i = 0; i < 4; ++i) ret.M[i][i] = 1;
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
 cin >> n;
 Matrix ans;
 for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) ans.M[i][j] = 1;
 for (int i = 0; i < 4; ++i) ans.M[i][i] = 0;
 ans = binpow(ans,n);
 cout << (ans.M[2][2]) << "\n";
 return 0;
}