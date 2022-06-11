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
sort r g and b vals
 
dp[i][j][k] stores the maximum area attainable with the last i red sticks, last j green sticks, and last k blue sticks
*/
 
const int nax = 2e2 + 5;
int n;
int dp[nax][nax][nax];
int R, G, B;
int RR[nax], GG[nax], BB[nax];
 
int solve(int r, int g, int b){
 if (r + g == 0 or g + b == 0 or r + b == 0) return 0;
 int& cur = dp[r][g][b];
 if (cur != -1) return cur;
 cur = 0;
 if (r != 0 and g != 0){
  cur = max(cur, solve(r - 1, g - 1, b) + RR[r - 1] * GG[g - 1]);
 }
 if (g != 0 and b != 0){
  cur = max(cur, solve(r, g - 1, b - 1) + GG[g - 1] * BB[b - 1]);
 }
 if (b != 0 and r != 0){
  cur = max(cur, solve(r - 1, g, b - 1) + BB[b - 1] * RR[r - 1]);
 }
 return cur; 
}
 
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(R,G,B);
 memset(dp, -1, sizeof(dp));
 f(R) in(RR[i]);
 f(G) in(GG[i]);
 f(B) in(BB[i]);
 sort(RR, RR + R);
 sort(GG, GG + G);
 sort(BB, BB + B);
 out(solve(R,G,B));
 
 return 0;
}