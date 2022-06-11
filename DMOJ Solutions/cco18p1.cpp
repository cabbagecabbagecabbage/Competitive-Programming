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
dp[i][j] stores the maximum amount of total points with the first i games from the first team and first j games from the second team
transition
	if ith game and jth game is a rivalry game
		dp[i][j] = dp[i-1][j-1] + score[i] + score[j]
	else
		dp[i][j] = dp[i-1][j-1]
*/

const int nax = 1e3 + 5;
string res1, res2;
int n, score1[nax], score2[nax];
int dp[nax][nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	in(res1);
	f2(1,n+1) in(score1[i]);
	in(res2);
	f2(1,n+1) in(score2[i]);
	res1 = " " + res1;
	res2 = " " + res2;
	f2(1,n+1){
		ff2(1,n+1){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if ((res1[i] == 'W' and res2[j] == 'L' and score1[i] > score2[j]) or
				(res2[j] == 'W' and res1[i] == 'L' and score1[i] < score2[j])){
				dp[i][j] = max(dp[i-1][j-1] + score1[i] + score2[j],dp[i][j]);
			}
		}
	}
	// f2(1,n+1){
	// 	ff2(1,n+1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	out(dp[n][n]);
	return 0;
}