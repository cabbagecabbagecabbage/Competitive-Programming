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
dp[i][0] is the shortest path from 1,1, to (i,l[i]) when the ith row has been satisfied
dp[i][1] is the shortest path from 1,1, to (i,r[i]) when the ith row has been satisfied
*/

const int nax = 2e4 + 5;
int n, dp[nax][2], l[nax], r[nax];


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	l[0] = r[0] = 1;
	dp[0][0] = dp[0][1] = -1;
	f2(1,n+1) in(l[i],r[i]);
	f2(1,n+1){
		int d = r[i] - l[i];
		//left
		dp[i][0] = min(dp[i-1][0] + abs(l[i-1] - r[i]), dp[i-1][1] + abs(r[i-1] - r[i])) + 1 + d;
		//right
		dp[i][1] = min(dp[i-1][1] + abs(r[i-1] - l[i]), dp[i-1][0] + abs(l[i-1] - l[i])) + 1 + d;
		// out(dp[i][0],dp[i][1]);
	}
	out(min(dp[n][0] + abs(n - l[n]), dp[n][1] + abs(n - r[n])));
	return 0;
}