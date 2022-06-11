#include <bits/stdc++.h>
using namespace std;
 
long long n,m;
bool dp[1005][1005];
 
int32_t main(){
 cin >> n >> m;
 if (n > m) cout << "YES\n";
 else {
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i){
   long long a; cin >> a; a %= m;
   for (int j = 0; j <= m; ++j){
    dp[i][j] = dp[i-1][j] || dp[i-1][(j-a+m)%m];
   }
  }
  cout << (dp[n][m] ? "YES" : "NO") << "\n";
 }
 return 0;
}