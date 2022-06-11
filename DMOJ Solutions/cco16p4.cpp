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
for every grid flip all possible 2 by 2 subgrids whose topleft is 'R'. This makes the subgrid 0,0 to n-2,n-2 consist of only 0's. changes are reversible so any 2 grids that can reach this position can be paired

*/

const int nax = 2e4 + 5;
int n,g;
string s;
unordered_map<int,int> m;
int grid[11][11];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,g);
	while (g--){
		f(n){
			in(s);
			ff(n){
				grid[i][j] = s[j] == 'R';
			}
		}
		f(n-1) ff(n-1){
			if (grid[i][j]){
				for (int a: {0,1}){
					for (int b: {0,1}){
						grid[i+a][j+b] = 1 - grid[i+a][j+b];
					}
				}
			}
		}
		// only need to consider last row and col
		int k = 0, ind = 0;
		f(n-1) k += (grid[i][n-1] << ind), ++ind;
		f(n) k += (grid[n-1][i] << ind), ++ind;
		++m[k];
	}
	
	int ans = 0;
	for (pii x: m){
		ans += x.second * (x.second - 1) / 2;
	}
	out(ans);
	return 0;
}