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
interpretation of someone's ac solution (i couldnt solve this)
lets say the interval is to the right of your position. it is never optimal to go past the left bound of the interval. traveling to any point between your position and the left bound (inclusive) yields the same cost but their optimality depends on the position of the rest of the intervals. therefore we keep and left and right bound of where our position could be, while maintaining a cost that is equal through in all positions of the interval
*/

const int nax = 5e3 + 5;

int n,x,a,b;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,x);
	int l = x, r = x;
	int cost = 0;
	f(n){
		in(a,b);
		if (l > b){
			//interval is to the left, shift interval in between [b,l]
			cost += l - b;
			r = l;
			l = b;
		}
		else if (r < a){
			//interval is to the right, shift interval in between [r,a]
			cost += a - r;
			l = r;
			r = a;
		}
		else{
			//intervals overlap. the positions outside the lightbulb interval will incur a cost while having the same cost to get there, therefore is not optimal. (the distance it might save from travelling will cancel out anyway)
			l = max(l,a);
			r = min(r,b);
		}
	}		
	out(cost);
	return 0;
}