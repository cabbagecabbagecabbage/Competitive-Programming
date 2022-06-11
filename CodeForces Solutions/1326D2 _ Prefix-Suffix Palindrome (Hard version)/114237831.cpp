#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define int     long long
#define f(a)     for (int i = 0; i < a; ++i)
#define ff(a)     for (int j = 0; j < a; ++j)
#define f2(a, b)    for (int i = a; i < b; ++i)
#define ff2(a, b)    for (int j = a; j < b; ++j)
#define fil(a, b)    fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define mem(a, b)   memset(a, b, sizeof(a))
#define min(a, b)    ((a) < (b) ? (a) : (b))
#define max(a, b)    ((a) > (b) ? (a) : (b))
#define inf     0x3f3f3f3f
#define llinf     0x3f3f3f3f3f3f3f3f
#define eb      emplace_back
typedef long long    ll;
typedef vector<int>   vi;
typedef pair<int, int>   pii;
 
/*
 
*/
 
const int nax = 2e6 + 5;
int pi[nax];
 
string prefix_palindrome(string s) {
 string k = s;
 reverse(k.begin(), k.end());
 s = s + "#" + k;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return s.substr(0,pi[n-1]);
}
 
void solve(){
 string s;
 in(s);
 string a = "";
 int l = 0, r = s.length()-1;
 while (r > l && s[l] == s[r]){
  a += s[l];
  l++; r--;
 }
 string b = a;
 reverse(b.begin(), b.end());
 if (l == r){
  out(a + s.substr(l,r-l+1) + b);
 }
 else{
  string sub = s.substr(l,r-l+1);
  string first = prefix_palindrome(sub);
  reverse(sub.begin(), sub.end());
  string second = prefix_palindrome(sub);
  if (first.length() > second.length()){
   out(a+first+b);
  }
  else out(a+second+b);
 }
  
}
  
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 int t; in(t);
 while (t--) solve();
 return 0;
}