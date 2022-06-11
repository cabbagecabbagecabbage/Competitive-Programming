#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
 int n; cin >> n;
 vector<int> a(n);
 for (int i = 0; i < n; ++i) cin >> a[i];
 for (int i = 0; i < n; ++i){
  for (int j = i+1; j < n; ++j){
   int o = a[i] | a[j];
   if (a[i] + a[j] > o){
    a[j] = o;
    a[i] = 0;
   }
  }
 }
 int ans = 0;
 for (int i = 0; i < n; ++i) ans += a[i];
 cout << ans << "\n";
}
 
int32_t main(){
 int t; cin >> t;
 while (t--) solve();
 return 0;
}