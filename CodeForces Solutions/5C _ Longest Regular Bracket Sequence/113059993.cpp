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
top of the stack stores the latest index that cannot be included in a regular substring i.e. a closing bracket that does not have a corresponding opening bracket, or an opening bracket that has not yet been closed
 
when a closing bracket is reached and there is an unmatched opening bracket, we can remove the open bracket because the 2 will form a pair which can be part of a substring. then we also know that the substring [top of the stack:i+1] is regular
 
if there isnt, we essentially erase the previous index that cannot be included with the current index (this is an unmatched bracket). that we there is always only 1 index at the bottom of the stack that represents the index that cant be matched with, so checking the stack size is sufficient for knowing that the length can be updated
*/
 
const int nax = 1e6 + 5;
string s;
 
int32_t main() {
 in(s);
 stack<int> last;
 last.push(-1);
 int maxlen = 0, cnt = 1;
 f(s.length()){
  if (s[i] == '('){
   last.push(i);
  }
  else if (s[i] == ')'){
   last.pop();
   if (last.size()){
    int len = i - last.top();
    if (len > maxlen){
     maxlen = len;
     cnt = 1;
    }
    else if (len == maxlen){
     cnt++;
    }
   }
   else last.push(i);
  }
 }
 out(maxlen,cnt);
 
}