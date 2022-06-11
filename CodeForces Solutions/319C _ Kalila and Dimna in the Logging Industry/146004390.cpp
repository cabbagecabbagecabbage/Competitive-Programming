#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct line {
 int m,b;
 int eval(int x){ return m*x+b; }
 double intx(line other){ return (double) (b-other.b) / (other.m-m); }
};
 
int32_t main(){
 int n; cin >> n;
 vector<int> a(n+1),b(n+1),dp(n+1);
 for (int i = 1; i <= n; ++i) cin >> a[i];
 for (int i = 1; i <= n; ++i) cin >> b[i];
 dp[1] = 0;
 //dp[i] = min{dp[j] + b[j]*a[i]}
 deque<line> cht;
 cht.push_front((line) {b[1],dp[1]});
 for (int i = 2; i <= n; ++i){
  int x = a[i];
  while (cht.size() > 1 and cht[0].eval(x) > cht[1].eval(x)) cht.pop_front();
  dp[i] = cht[0].eval(x);
  line curline = (line) {b[i],dp[i]};
  while (cht.size() > 1 and curline.intx(cht.back()) < cht.back().intx(cht[cht.size()-2])) cht.pop_back();
  cht.push_back(curline);
 }
 cout << dp[n] << "\n";
 return 0;
}