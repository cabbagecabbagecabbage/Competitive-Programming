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
 
const int nax = (1 << 17) + 5;
 
struct Node{
 int l, r, val, height;
};
 
int arr[nax];
Node tree[nax*4];
int n,m,q,p,b;
 
void merge(int v){
 int left = v << 1, right = left | 1;
 tree[v].height = tree[left].height + 1;
 if (tree[v].height % 2){
  tree[v].val = tree[left].val | tree[right].val;
 }
 else{
  tree[v].val = tree[left].val ^ tree[right].val;
 }
}
 
void build(int v, int l, int r){
 tree[v].l = l; tree[v].r = r;
 if (l == r){
  tree[v].val = arr[l];
  tree[v].height = 0;
  return;
 }
 int m = (l + r) / 2, left = v << 1, right = left | 1;
 build(left, l, m);
 build(right, m + 1, r);
 merge(v);
}
 
void update(int v, int idx, int val){
 int l = tree[v].l, r = tree[v].r;
 if (l == r){
  tree[v].val = val;
  return;
 }
 int m = (l + r) / 2, left = v << 1, right = left | 1;
 if (idx <= m) update(left, idx, val);
 else update(right, idx, val);
 merge(v);
}
 
int main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 in(n,m);
 f((1 << n)) in(arr[i]);
 build(1,0,(1 << n) - 1);
 while (m--){
  in(p,b);
  update(1,--p,b);
  out(tree[1].val);
 }
 return 0;
}