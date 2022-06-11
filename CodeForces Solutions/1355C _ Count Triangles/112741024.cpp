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
 
#define int    long long
#define f(a)    for (int i = 0; i < a; ++i)
#define ff(a)    for (int j = 0; j < a; ++j)
#define f2(a, b)   for (int i = a; i < b; ++i)
#define ff2(a, b)   for (int j = a; j < b; ++j)
#define mem(a, b)   fill(a, a + (sizeof(a)/sizeof(*a)), b)
#define min(a, b)   ((a) < (b) ? (a) : (b))
#define max(a, b)   ((a) > (b) ? (a) : (b))
#define inf    0x3f3f3f3f
#define llinf    0x3f3f3f3f3f3f3f3f
#define eb     emplace_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
only have to satisfy x + y > z
let sum[i] store the number of ways x + y can obtain the sum i
for every x, we want to add all possible y from B to C
so we add one to all indices in the interval [x+C,x+B]
use diff array
turn diff array into psa
for every possible z, add on the number of possible ways for each possible sum (sums that are in the range [z + 1, B + C]
*/
 
const int nax = 1e6 + 5;
int a,b,c,d,x,y,z;
 
int arr[nax];
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(a,b,c,d);
 int ans = 0;
 
 for (int x = a; x <= b; ++x){
  arr[x + b]++;
  arr[x + c + 1]--;
 }
 f2(1,nax){
  arr[i] += arr[i-1];
 }
 f2(1,nax){
  arr[i] += arr[i-1];
 }
 for (int z = c; z <= d; ++z){
  ans += arr[b + c] - arr[z];
 }
 out(ans);
 
 return 0;
}