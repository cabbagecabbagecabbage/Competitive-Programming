#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") //can cause RTE on some sites
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <ext/pb_ds/tree_policy.hpp>
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
#define outs(a)				cout << a << " "
#define nl()				cout << "\n"
#define inf 				0x3f3f3f3f
#define llinf 				0x3f3f3f3f3f3f3f3f
#define eb 					emplace_back
typedef vector<int> 		vi;
typedef pair<int, int> 		pii;
typedef vector<pair<int,int>> vpii;

/*
dp[i] stores the minimum number of moves needed to turn off the first i groups of lights
*/

const int nax = 20 + 5, mod = 1e9 + 7;
int k,arr[nax],dp[nax];
pii on[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(k);
	int start = -1, cur = 1;
	bool going = false;
	f(k){
		in(arr[i]);
		if (going and !arr[i]){
			going = false;
			on[cur++] = {start,i-1};
		}
		else if (!going and arr[i]){
			going = true;
			start = i;
		}
	}
	if (going and arr[k-1]) on[cur++] = {start,k-1};
	
	//do dp by groups
	mem(dp,inf);
	dp[0] = 0;
	f2(1,cur){
		int span, cnt = 0;
		for (int j = i; j >= 1 and (span = on[i].second - on[j].first + 1) <= 7; --j){
			//attempt to merge on [j,i]
			//if span 7 then middle cant be filled
			//if span 6 then middle 2 cant be both filled
			//less than 6 always possible
			if (span == 7 and arr[on[j].first+3]) continue;
			if (span == 6 and arr[on[j].first+2] and arr[on[j].first+3]) continue;
			cnt += on[j].second - on[j].first + 1;
			dp[i] = min(dp[i], dp[j-1] + (max(4, span) - cnt));
		}
	}
	out(dp[cur-1]);
	return 0;
}