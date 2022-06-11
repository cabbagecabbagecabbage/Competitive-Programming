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
#define fil(a, b) 			fill(a, a + (sizeof(a)/sizeof(*a)), b)
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
start bottom left, go top right
each square check whether the line intersects top edge or right edge
proceed to that square
line: 	y = (m/n)x
		x = (n/m)y
*/

const int nax = 1e0 + 5;
vector<pii> coors;
int n,m;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	in(n,m);
	int y = 1, x = 1, ans = 1;
	//define squares by their top right corner
	while (y != n or x != m){
		coors.eb(y,x);
		ans++;
		//check top edge
		// double xp = (double) y * slope;
		// out(xp);
		if (y * m > (x-1) * n and x * n > y * m){
			y += 1;
			continue;
		}
		
		// out(yp);
		if (x * n > (y - 1) * (m) and y * m > x * n){
			x += 1;
			continue;
		}
		
		else{
			y += 1;
			x += 1;
		}
	}
	coors.eb(n,m);
	out(ans);
	sort(coors.begin(), coors.end());
	for (pii k: coors){
		out(k.first,k.second);
	}
	return 0;
}