#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
// #define int 				long long
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

const int nax = 1e6 + 5;
int n, xtor[nax];

typedef tree<pii,null_type,greater<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set ratings;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	while (n--){
		char op; in(op);
		if (op == 'N'){
			int x,r; in(x,r);
			ratings.insert({r,x});
			xtor[x] = r;
		}
		else if (op == 'M'){
			int x,r; in(x,r);
			ratings.erase({xtor[x],x});
			ratings.insert({r,x});
			xtor[x] = r;
		}
		else{
			int k; in(k);
			pii x = *ratings.find_by_order(k-1);
			out(x.second);
		}
	}
	return 0;
}