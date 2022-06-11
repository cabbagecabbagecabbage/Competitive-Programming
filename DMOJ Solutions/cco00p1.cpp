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

*/

const int nax = 1e3 + 5;
int n;
unordered_map<char, vector<char>> adj;
unordered_map<char, int> vis;
vector<char> mentioned;

bool isupper(char c){
	return ('A' <= c and c <= 'Z');
}

vector<char> dfs(char node, char parent){
	vector<char> ret;
	vis[node] = 1;
	if (!isupper(node)){
		ret.eb(node);
		return ret;
	}
	for (char c: adj[node]){
		if (!vis[c]){
			for (char d: dfs(c, node)){
				ret.eb(d);
			}
		}
	}
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// out(isupper('R'));
	in(n);
	f(n){
		char a, b;
		string x;
		in(a,x,b);
		adj[a].eb(b);
		if (!vis[a]){
			mentioned.eb(a);
			vis[a] = 1;
		}
		if (!vis[b] and isupper(b)){
			mentioned.eb(b);
			vis[b] = 1;
		}
	}
	sort(mentioned.begin(),mentioned.end());
	// for (char s: mentioned) out(s);
	for (char s: mentioned){
		for (pair<char, int> x: vis){
			vis[x.first] = 0;
		}
		vector<char> e = dfs(s,s);
		cout << s << " = {";
		if (e.size() > 0){
			sort(e.begin(),e.end());
			f(e.size()-1){
				cout << e[i] << ",";
			}
			cout << e[e.size()-1];
		}
		cout << "}\n";
	}
	return 0;
}