#include <bits/stdc++.h>
using namespace std;
set<string> str;
vector<string> strs;
void solve(){
 int n; cin >> n;
 str.clear();
 strs.clear();
 for (int i = 0; i < n; ++i){
  string s; cin >> s;
  strs.push_back(s);
 }
 for (int i = 0; i < n; ++i){
  string s = strs[i];
  if (s.length() == 1){
   cout << "YES\n";
   return;
  }
  string t = s;
  reverse(t.begin(), t.end());
  if (str.count(t)){
   cout << "YES\n";
   return;
  }
  if (s.length() == 2){
   if (s[0] == s[1]){
    cout << "YES\n";
    return;
   }
   for (char c: "abcdefghijklmnopqrstuvwxyz"){
    if (str.count(t+c)){
     cout << "YES\n";
     return;
    }
   }
  }
  if (s.length() == 3){
   if (s[0] == s[2]){
    cout << "YES\n";
    return;
   }
   string c = s.substr(1);
   reverse(c.begin(),c.end());
   if (str.count(c)){
    cout << "YES\n";
    return;
   }
  }
  str.insert(strs[i]);
 }
 cout << "NO\n";
}
  
  
 
int32_t main(){
 int t; cin >> t;
 while (t--) solve();
 return 0;
}