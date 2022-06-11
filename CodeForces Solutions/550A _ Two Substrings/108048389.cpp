#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (decltype(a) i = 0; i < a; ++i)
#define ff(a) for (decltype(a) j = 0; j < a; ++j)
#define f2(a, b) for (decltype(a) i = a; i < b; ++i)
#define ff2(a, b) for (decltype(a) j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
 
const ll nax = 1e5 + 5;
string s;
bool ba = false, ab = false;
 
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(s);
 int l = s.length();
 int i = 0;
 while (i < l-1){
  if (!ab){
   if (s[i] == 'A' and s[i+1] == 'B'){
    ab = true;
    i += 2;
    continue;
   }
  }
  else if (!ba){
   if (s[i] == 'B' and s[i+1] == 'A'){
    ba = true;
    i++;
   }
  }
  ++i;
 }
 if (ba and ab){
  out("YES");
  return 0;
 }
 ba = false;
 ab = false;
 i = 0;
 while (i < l-1){
  if (!ba){
   if (s[i] == 'B' and s[i+1] == 'A'){
    ba = true;
    i += 2;
    continue;
   }
  }
  else if (!ab){
   if (s[i] == 'A' and s[i+1] == 'B'){
    ab = true;
    i++;
   }
  }
  ++i;
 }
 if (ba and ab){
  out("YES");
 }
 else out("NO");
 
 return 0;
}