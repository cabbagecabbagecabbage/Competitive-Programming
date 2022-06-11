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
#define int 				long long
#define f(a) 				for (int i = 0; i < a; ++i)
#define ff(a) 				for (int j = 0; j < a; ++j)
#define f2(a, b) 			for (int i = a; i < b; ++i)
#define ff2(a, b) 			for (int j = a; j < b; ++j)
#define fil(arr, val) fill((remove_array<decltype(arr)>::type*)&arr, (remove_array<decltype(arr)>::type*)((char*)&arr + sizeof(arr)), val)
template<typename T> struct remove_array {typedef T type;};
template<typename T, size_t sz> struct remove_array<T[sz]> { typedef typename remove_array<T>::type type;};
#define mem(a, b)			memset(a, b, sizeof(a))
#define min(a, b) 			((a) < (b) ? (a) : (b))
#define max(a, b) 			((a) > (b) ? (a) : (b))
#define inf 				0x3f3f3f3f
#define llinf 				0x3f3f3f3f3f3f3f3f
#define eb 					emplace_back
typedef long long 			ll;
typedef vector<int> 		vi;
typedef pair<int, int> 		pii;

/*

*/

struct Node{
	int l,r,ind,val,h;
};

const int nax = 1048576 + 5;
int n,m,arr[nax],won[nax];
Node tree[nax*4];

void up(int v){
	if (tree[v*2].val > tree[v*2+1].val){	
		tree[v].val = tree[v*2].val;
		tree[v].ind = tree[v*2].ind;
		tree[v].h = tree[v*2].h + 1;
		won[tree[v*2+1].ind] = tree[v*2+1].h;
	}
	else{
		tree[v].val = tree[v*2+1].val;
		tree[v].ind = tree[v*2+1].ind;
		tree[v].h = tree[v*2+1].h + 1;
		won[tree[v*2].ind] = tree[v*2].h;
	}
	won[tree[v].ind] = tree[v].h;
}

void build(int v, int l, int r){
	tree[v].l = l; tree[v].r = r;
	if (l == r){
		tree[v].ind = l;
		tree[v].val = arr[l];
		tree[v].h = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(v*2, l, mid);
	build(v*2 + 1, mid + 1, r);
	up(v);
}

void update(int v, int ind, int val){
	if (tree[v].l == tree[v].r){
		tree[v].val = val;
		return;
	}
	int mid = (tree[v].l + tree[v].r) / 2;
	if (ind <= mid){
		update(v*2, ind, val);
	}
	else update(v*2+1, ind, val);
	up(v);
}

int query(){
	return tree[1].ind;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,m);
	f2(1,(1 << n)+1) in(arr[i]);
	build(1,1,(1 << n));
	while (m--){
		char op;
		in(op);
		if (op == 'R'){
			int x,y;
			in(x,y);
			update(1,x,y);
		}
		else if (op == 'W'){
			out(query());
		}
		else{
			int x;
			in(x);
			out(won[x]);
		}
	}
	return 0;
}