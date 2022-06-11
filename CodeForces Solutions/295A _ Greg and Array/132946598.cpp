#include <bits/stdc++.h>
using namespace std;
#define int long long
 
/*
 
*/
 
const int nax = 1e5 + 5;
int arr[nax],diff[nax],op[nax];
pair<pair<int,int>,int> lrd[nax];
int n,m,k;
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 cin >> n >> m >> k;
 for (int i = 1; i <= n; ++i){
  cin >> arr[i];
 }
 for (int i = 1; i <= m; ++i){
  cin >> lrd[i].first.first >> lrd[i].first.second >> lrd[i].second;
 }
 for (int i = 1; i <= k; ++i){
  int x,y; cin >> x >> y;
  ++op[x]; --op[y+1];
 }
 for (int i = 1; i <= m; ++i){
  op[i] += op[i-1];
  diff[lrd[i].first.first] += lrd[i].second * op[i];
  diff[lrd[i].first.second+1] -= lrd[i].second * op[i];
 }
 for (int i = 1; i <= n; ++i){
  diff[i] += diff[i-1];
  cout << arr[i] + diff[i] << " ";
 }
 cout << "\n";
 
 return 0;
}