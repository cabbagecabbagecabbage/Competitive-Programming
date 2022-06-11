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
 
const int nax = 500 + 5;
int n, m, k, already = 0;
string s;
int grid[nax][nax];
 
pii dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
 
void solve(pii start){
 queue<pii> q;
 q.push(start);
 int x,y;
 int want = n*m - already - k;
 // out(want);
 while (!q.empty()){
  tie(y,x) = q.front(); q.pop();
  if (grid[y][x] == 2) continue;
  grid[y][x] = 2;
  if (--want == 0) return;
  for (pii k: dirs){
   int ny = y + k.first, nx = x + k.second;
   if (0 <= ny and ny < n and 0 <= nx and nx < m){
    if (grid[ny][nx] == 0){
     q.push({ny,nx});
    }
   }
  }
 }
} 
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,m,k);
 pii start;
 f(n){
  in(s);
  ff(m){
   if (s[j] == '#'){
    grid[i][j] = 1;
    already++;
   }
   else{
    grid[i][j] = 0;
    start.first = i; start.second = j;
   }
  }
 }
 solve(start);
 f(n){
  ff(m){
   if (grid[i][j] == 1){
    cout << "#";
   }
   else if (grid[i][j] == 0){
    cout << "X";
   }
   else {
    cout << ".";
   }
   // cout << grid[i][j];
  }
  cout << "\n";
 }
 
 
 return 0;
}