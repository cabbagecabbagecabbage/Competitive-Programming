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
prefix sum of occurences of 1's in a

notice 1's can only move to the right
so if we traverse array B, if at any index the number of occurences of 1's in the prefix of B is greater than the prefix of A, it is impossible

notice each stroke moves all 1's in the range to the right
to minimize strokes we go by segments of 1's in B

go in reverse i think
*/

const int nax = 5e5 + 5;
int n, a[nax], b[nax], ac = 0, bc = 0;
vector<pii> ans;
vi bi, ai;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	f(n){
		in(a[i]);
		if (a[i] == 1) ai.eb(i), ++ac;
	}
	f(n){
		in(b[i]);
		if (b[i] == 1) bi.eb(i), ++bc;
	}
	if (ac != bc){
		out(-1);
		return 0;
	}
	f(ac){
		if (ai[i] > bi[i]){
			out(-1);
			return 0;
		}
	}
	int pA = n-1, pB = n-1, started, cnt;
	bool extending = false;
	while (pB >= 0){
		if (extending){
			if (b[pB] == 0){
				//stopped extending
				int len = started - pB - cnt;
				pA = min(pA,pB);
				while (len){
					if (a[pA] == 1){
						len--;
						a[pA] = 0;
					}
					pA--;
				}
				ans.eb(pA+1, started);
				extending = false;
			}
			else{
				if (a[pB] == 1) cnt++;
				a[pB] = 1;
			}
		}
		else{
			if (b[pB] == 1 and a[pB] != 1){
				extending = true;
				started = pB;
				if (a[pB] == 1) cnt++;
				a[pB] = 1;
				cnt = 0;		
			}
		}
		pB--;
	}
	out(ans.size());
	for (pii k: ans){
		out(k.first+1,k.second+1);
	}
	return 0;
}