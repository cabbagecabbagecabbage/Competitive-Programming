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
 
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 ll k;
 vector<int> thing(10,1);
 // for (int x: thing) cout << x << " "; cout << "\n";
 ll product = 1;
 in(k);
 int cur = 0;
 while (product < k){
  product /= thing[cur];
  product *= ++thing[cur];
  cur = (cur + 1) % 10;
 }
 // for (int x: thing) cout << x << " "; cout << "\n";
 // out(thing[0]);
 f(thing[0]) cout << "c";
 f(thing[1]) cout << "o";
 f(thing[2]) cout << "d";
 f(thing[3]) cout << "e";
 f(thing[4]) cout << "f";
 f(thing[5]) cout << "o";
 f(thing[6]) cout << "r";
 f(thing[7]) cout << "c";
 f(thing[8]) cout << "e";
 f(thing[9]) cout << "s";
 return 0;
}