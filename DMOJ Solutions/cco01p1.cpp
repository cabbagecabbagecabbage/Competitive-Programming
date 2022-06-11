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

const int nax = 1e2 + 5;
int n, vis[nax], len = 0;
int adj[nax];

int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b){return a * b / gcd(a, b);}

void dfs(int node){
	++len;
	vis[node] = 1;
	if (!vis[adj[node]]) dfs(adj[node]);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (1){
		in(n);
		if (n == 0) break;
		f(n){
			int a,b;
			in(a,b);
			adj[a] = b;
		}
		int ans = 1;
		f2(1,n+1){
			if (!vis[i]){
				len = 0;
				dfs(i);
				ans = lcm(ans,len);
			}
		}		
		out(ans);
		mem(vis,0);
		mem(adj,0);
	}
		
	return 0;
}