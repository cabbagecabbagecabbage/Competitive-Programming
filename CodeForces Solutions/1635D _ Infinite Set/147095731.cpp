#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int mod = 1e9 + 7;
 
int32_t main(){
 int n,p; cin >> n >> p;
 vector<int> dp(p+1);
 vector<int> a(n);
 unordered_set<int> s;
 for (int i = 0; i < n; ++i) cin >> a[i];
 sort(a.begin(),a.end());
 for (int i = 0; i < n; ++i){
  int largestbit = p+1;
  for (int j = 63; j >= 0; --j){
   if ((1ll << j) & a[i]){
    largestbit = j;
    break;
   }
  }
  if (largestbit >= p) continue;
  
  
  function<bool(int)> check = [&](int num){
   if (num <= 0) return true;
   if (s.count(num)) return false;
   if (num % 4 == 0 and check(num / 4) == false) return false;
   if (num % 2 == 1 and check((num - 1) / 2) == false) return false;
   return true;
  };
  
  // bool flag = true;
  // int b = a[i];
  // while (b > 0){
   // if (s.count(b)){
    // flag = false;
    // break;
   // }
   // if (b % 4 == 0){
    // b /= 4;
   // }
   // else break;
  // }
  // int c = a[i];
  // while (c > 0){
   // if (s.count(c)){
    // flag = false;
    // break;
   // }
   // if (c % 2 == 1){
    // c -= 1;
    // c /= 2;
   // }
   // else break;
  // }
  if (check(a[i])){
   s.insert(a[i]);
   dp[largestbit+1]++;
  }
 }
 int ans = 0;
 for (int i = 0; i <= p; ++i){
  if (i+1 <= p){
   dp[i+1] += dp[i];
   dp[i+1] %= mod;
  }
  if (i+2 <= p){
   dp[i+2] += dp[i];
   dp[i+2] %= mod;
  }
  ans += dp[i];
  ans %= mod;
 }
 cout << (ans+mod) % mod << "\n";
 return 0;
}