#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define int long long
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
if the biggest is greater than 2 times the sum of the other 2, then we always take 2 balloons from it and 1 balloon from whichever isnt empty, therefore the answer is the sum of the smallest 2
if the biggest is smaller than 2 times the sum of the other 2, then the 3 numbers are always reducible to a state where the difference between the largest and the smallest is less than or equal to 1. therefore the answer is the floor of the sum of the 3 numbers over 3
*/
 
const int nax = 1e5 + 5;
int r,g,b;
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(r,g,b);
 vi l;
 l.eb(r); l.eb(g); l.eb(b);
 sort(l.begin(),l.end());
 int a = l[0], b = l[1], c = l[2];
 if (2*(a+b) <= c){
  out(a+b);
 }
 else{
  out((a+b+c) / 3);
 }
 return 0;
}