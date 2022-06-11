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
 
const int nax = 1e0 + 5;
 
bool reached = false;
string first;
int n, final = -inf;
string name;
int points;
unordered_map<string,int> m, mm;
vector<pair<string,int>> thing;
unordered_set<string> s;
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n);
 f(n){
  in(name,points);
  m[name] += points;
  thing.emplace_back(name,points);
 }
 for (pair<string, int> k: thing){
  final = max(final, m[k.first]);
 }
 for (pair<string, int> k: thing){
  if (final == m[k.first]) s.insert(k.first);
 }
 // out(final); 
 for (pair<string, int> k: thing){
  mm[k.first] += k.second;
  if (mm[k.first] >= final && s.count(k.first)){
   out(k.first);
   return 0;
  }
 }
 
 
 return 0;
}