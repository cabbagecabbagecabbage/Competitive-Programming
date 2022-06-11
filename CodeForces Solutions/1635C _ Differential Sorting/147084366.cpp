#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
 int n; cin >> n;
 vector<int> a(n+1);
 for (int i = 1; i <= n; ++i) cin >> a[i];
 int ans = 0;
 if (a[n] < a[n-1]){
  cout << -1 << "\n";
  return;
 }
 vector<tuple<int,int,int>> q;
 for (int i = n-2; i >= 1; --i){
  if (a[i] > a[i+1]){
   if (a[i+1] - a[n] <= a[i+1]){
    a[i] = a[i+1] - a[n];
    ++ans;
    q.emplace_back(i,i+1,n);
   }
   else {
    cout << -1 << "\n";
    return;
   }
  }
 }
 cout << ans << "\n";
 for (auto[a,b,c]: q){
  cout << a << " " << b << " " << c << "\n";
 }
}
 
int32_t main(){
 int t; cin >> t;
 while (t--) solve();
 return 0;
}