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

*/

const int nax = 1e6 + 5;
int n,tot = 0,pref[nax],arr[nax];

int sum(int left, int right){
	int ans;
	if (left > right){
		ans = tot - (pref[left] - pref[right+1]);
	}
	else ans = pref[right+1] - pref[left];
	// out(left,right,ans);
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n);
	f(n){
		in(arr[i]);
		pref[i+1] = arr[i] + pref[i];
		tot += arr[i];
	}
	// out(tot,pref[4],pref[1+1]);
	for (int start = 0; start < n; ++start){
		// int start = 2;
		int lo = 0, hi = n-2, mid, ans = llinf;
		while (lo <= hi){
			// out("lo ",lo," hi",hi);
			mid = (lo + hi) / 2;
			int leftsum = sum((start)%n,(start+mid)%n), rightsum = tot - leftsum;
			if (abs(leftsum - rightsum) < ans){
				ans = abs(leftsum - rightsum);
			}
			else if (leftsum > rightsum){
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}
		cout << ans;
		if (start != n-1) cout << " ";
	}
	cout << "\n";
	
	return 0;
}