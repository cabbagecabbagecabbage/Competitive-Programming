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
#define fil(a, b) 			fill(a, a + (sizeof(a)/sizeof(*a)), b)
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
https://www.fatalerrors.org/a/criminal-detention-in-noip-2010-food-chain-of-noi-2001.html
2 numbers being in the same sets means that their relative order is decided within that case
cyclic therefore symmetrical sets: only needs to check one of the cases
but we still need to update them all because we dont know how the updates will affect later queries
	
*/

const int nax = 5e4 + 5;
int n,k,op,x,y;
int parent[nax*3], size[nax*3];

int Find(int node){
	return parent[node] = (node == parent[node] ? node : Find(parent[node]));
}

void Merge(int a, int b){
	int pa = Find(a), pb = Find(b);
	if (pa == pb) return;
	if (size[pa] < size[pb]) swap(pa,pb);
	parent[pb] = pa;
	size[pa] += size[pb];
}


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,k);
	f(3*n+1) parent[i] = i, size[i] = 1;
	int lies = 0;
	while (k--){
		in(op,x,y);
		
		if (x > n or y > n){
			lies++;
			continue;
		}
		
		if (op == 1){
			//if x and y would be in the same set, y cant eat x and x cant eat y
			if (Find(x) == Find(y+n) or Find(x+n) == Find(y)){
				lies++;
				continue;
			}
			Merge(x,y), Merge(x+n,y+n), Merge(x+2*n, y+2*n);
		}
		else if (op == 2){
			//if x eats y, y cant be x, y cant eat x
			if (Find(x) == Find(y) or Find(y) == Find(x+n)){
				lies++;
				continue;
			}
			Merge(x,y+n), Merge(x+n,y+2*n), Merge(x+2*n,y);
		}
	}
	out(lies);
}