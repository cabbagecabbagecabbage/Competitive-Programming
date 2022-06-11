#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define int long long
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const int nax = 2e5 + 5;
string s;
string chars = "0123456789";
int t;
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(t);
 while (t--){
  in(s);
  int l = s.length();
  int ans = 0;
 
  for (char c: chars){
   int temp = 0;
   f(l){
    if (s[i] == c){
     temp++;
    }
   }
   ans = max(ans,temp);
  }
 
 
  for (char c: chars){
   for (char cc: chars){
    string something = "";
    f(l){
     if (s[i] == c){
      if (something == "" or something[something.length()-1] == cc){
       something += c;
      }
     }
     else if (s[i] == cc){
      if (something == "" or something[something.length()-1] == c){
       something += cc;
      }
     }
    }
    // out(something);
    if (something.length() % 2) ans = max(ans,(int) something.length()-1);
    else ans = max(ans,(int) something.length());
   }
  }
   
  out(l-ans);
 }
 
 return 0;
}