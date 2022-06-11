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
wait wtf this might work
*/

const int nax = 1e5 + 5;
int n, w, a[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,w);
	f(n){
		in(a[i]);
	}
	sort(a, a + n);

	//min
	if (a[0] <= w and w <= a[n-1]){
		cout << (w - a[0] + a[n-1] - w);
	}
	else if (w < a[0]){
		cout << (a[0] - w + a[n-1] - a[0]);
	}
	else if (w > a[n-1]){
		cout << (w - a[n-1] + a[n-1] - a[0]);
	}
	cout << " ";
	
	//max
	int ans = 0;
	int left = 0, right = n-1, big = 0, pre = w;
	bool isleft = true;
	while (left <= right){
		if (isleft){
			big += max(abs(pre - a[left]), abs(w - a[left]));
			pre = a[left];
			left++;
			isleft = false;
		}
		else{
			big += max(abs(pre - a[right]), abs(w - a[right]));
			pre = a[right];
			right--;
			isleft = true;
		}
	}
	ans = max(ans, big);


	left = 0, right = n-1, big = 0, pre = w;
	isleft = false;
	while (left <= right){
		if (isleft){
			big += max(abs(pre - a[left]), abs(w - a[left]));
			pre = a[left++];
			isleft = false;
		}
		else{
			big += max(abs(pre - a[right]), abs(w - a[right]));
			pre = a[right--];
			isleft = true;
		}
	}
	ans = max(ans, big);

	out(ans);
	return 0;
}