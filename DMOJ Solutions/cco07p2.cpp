#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
take the 6 numbers. hash all cyclic shifts. reverse and repeat. sort all hashes. take smallest
*/

const int nax = 1e5 + 5;
int n;
gp_hash_table<int,int> t;
deque<int> nums;
vi hashes;
int bases[6] = {1, 37, 1369, 50653, 1874161, 69343957};

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	f(n){
		ff(6){
			int a;
			in(a);
			nums.eb(a);
		}
		ff(6){
			int h1 = 0, h2 = 0;
			for (int k = 0; k < 6; ++k){
				h1 += nums[k] * bases[k];
				h2 += nums[k] * bases[5-k];
				
			}
			hashes.eb(h1);
			hashes.eb(h2);
			nums.push_back(nums.front());
			nums.pop_front();
		}
		sort(hashes.begin(),hashes.end());
		if (t.find(hashes[0]) != t.end()){
			out("Twin snowflakes found.");
			return 0;
		}
		else t[hashes[0]] = 1;
		hashes.clear();
		nums.clear();
	}
	out("No two snowflakes are alike.");
	return 0;
}