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

*/

const int nax = 1e5 + 5;
int n,q;
int par[nax],size[nax];
int Find(int node){
	return (node == par[node] ? node : par[node] = Find(par[node]));
}
void Merge(int a, int b){
	int pa = Find(a), pb = Find(b);
	if (pa == pb) return;
	if (size[pa] < size[pb]) swap(pa,pb);
	size[pa] += size[pb];
	par[pb] = pa;
}
	
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,q);
	f(n+1) par[i] = i, size[i] = 1;
	while (q--){
		// f2(1,n+1) out(i,Find(i));
		int op;
		in(op);
		if (op == 1){
			int u,v;
			in(u,v);
			Merge(u,v);
		}
		else{
			int x;
			in(x);
			out(size[Find(x)]);
		}
	}
	
	return 0;
}