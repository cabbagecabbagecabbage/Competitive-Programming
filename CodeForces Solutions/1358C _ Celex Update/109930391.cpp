#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (int i = 0; i < a; ++i)
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
 
const int nax = 1e0 + 5;
int A[nax];
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 ll n,a,b,c,d;
 in(n);
 f(n){
  in(a,b,c,d);
  out((d-b)*(c-a) + 1);
 }
 return 0;
}