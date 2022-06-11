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
neg slope diagonal defined by the difference between row and col
pos slope diagonal defined by the sum of row and col
*/
 
const int nax = 2e3 + 5;
int n,pos[nax*2], neg[nax*2], arr[nax][nax];
int whitebest = 0, blackbest = 0;
pii wb = {0,0}, bb = {1,0};
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n);
 f(n){
  ff(n){
   int x;
   in(x);
   arr[i][j] = x;
   pos[i+j] += x;
   neg[i-j+n] += x;
  }
 }
 f(n){
  ff(n){
   int val = pos[i+j] + neg[i-j+n] - arr[i][j];
   if ((i + j) % 2){
    if (val > whitebest){
     wb.first = i;
     wb.second = j;
     whitebest = val;
    }
   }
   else{
    if (val > blackbest){
     bb.first = i;
     bb.second = j;
     blackbest = val;
    }
   }
  }
 }
 cout << whitebest + blackbest << "\n";
 cout << wb.first + 1 << " " << wb.second + 1 << " ";
 cout << bb.first + 1 << " " << bb.second + 1 << "\n";
}