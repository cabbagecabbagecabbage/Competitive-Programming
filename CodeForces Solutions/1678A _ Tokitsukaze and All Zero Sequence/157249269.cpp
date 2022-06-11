#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
vi rv(int l){vi v(l);generate(all(v),ri);return v;}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}
void out(pii x){sp(x.first);out(x.second);}
#define var(x) sp(#x); out(x)
 
 
const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;
 
/*
 
*/
 
void solve(){
 int n = ri();
 unordered_map<int,int> u;
 vi a = rv(n); int cnt = 0;
 for (int i = 0; i < n; ++i){
  if (a[i]) ++cnt;
 }
 if (cnt != n){
  out(cnt);
  return;
 }
 for (int i = 0; i < n; ++i){
  if (++u[a[i]] > 1){
   out(cnt);
   return;
  }
 }
 out(cnt+1);
}
 
signed main(){
 cin.tie(0)->sync_with_stdio(0);
 int t = ri();
 while (t--) solve();
 return 0;
}