#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
 int n; cin >> n;
 vector<int> a(n+1);
 for (int i = 0; i < n; ++i) cin >> a[i];
 int ans = 0;
 for (int i = 1; i < n-1; ++i){
  if (a[i] > a[i-1] and a[i] > a[i+1]){
   a[i+1] = max(a[i+2],a[i]);
   ++ans;
  }
 }
 cout << ans << "\n";
 for (int i = 0; i < n; ++i){
  cout << a[i] << " \n"[i == n-1];
 }
}
 
int32_t main(){
 int t; cin >> t;
 while (t--) solve();
 return 0;
}