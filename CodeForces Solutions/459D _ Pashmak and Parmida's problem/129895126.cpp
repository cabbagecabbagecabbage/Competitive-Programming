#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
 
tree<pair<int,int>,null_type,greater<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> prefixes;
 
/*
let p[i] store the result of f(1,i,a[i])
let s[i] store the result of f(i,n,a[i])
once calculated, iterate and maintain bbst
*/
 
const int nax = 1e6 + 5;
int n, a[nax], p[nax], s[nax];
unordered_map<int,int> table;
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 cin >> n;
 for (int i = 1; i <= n; ++i){
  cin >> a[i];
  p[i] = ++table[a[i]];
 }
 table.clear();
 for (int i = n; i >= 1; --i){
  s[i] = ++table[a[i]];
 }
 int ans = 0;
 for (int i = 1; i <= n; ++i){
  ans += prefixes.order_of_key({s[i],0x3f3f3f3f});
  prefixes.insert({p[i],i});
 }
 cout << ans << "\n";
 
 return 0;
}