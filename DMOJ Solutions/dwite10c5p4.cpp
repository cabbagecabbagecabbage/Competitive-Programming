#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> void in(T& x){ cin >> x; }
template<typename T, typename... Args> void in(T& x, Args&...args){ cin >> x, in(args...); }
template<typename T> void out(const T& x){ cout << x << "\n"; }
template<typename T, typename... Args> void out(const T& x, const Args&...args){ cout << x << " ", out(args...); }
#define f(a) for (decltype(a) i = 0; i < a; ++i)
#define ff(a) for (decltype(a) j = 0; j < a; ++j)
#define f2(a, b) for (decltype(a) i = a; i < b; ++i)
#define ff2(a, b) for (decltype(a) j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

/*
dp[i][j] stores whether the interval [i,j] is solvable
*/

int dp[155][155];

string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ff(5){
		int test = 5;
		string final = "";
		while (test--){
			mem(dp,0);
			in(s);
			// out(s);
			int n = s.length();
			f(n){
				dp[i][i-1] = 1;
			}
			for (int length = 1; length < n; length++){
				for (int left = 0; left + length < n; left++){
					int right = left + length;
					for (int j = left; j <= right-1; ++j){
						if (dp[left][j] && dp[j+1][right]) dp[left][right] = 1;
					}
					if (s[right] == s[left]){
						// out(left,right);
						dp[left][right] = max(dp[left][right], dp[left+1][right-1]);
						for (int j = left+1; j <= right-1; ++j){
							if (s[j] == s[left]){
								if (dp[left+1][j-1] and dp[j+1][right-1]){
									dp[left][right] = 1;
								}
							}
						}
					}
				}
			}
			// out(dp[1][2]);
			if (dp[0][n-1]) final += "S";
			else final += "U";
		}
		out(final);
	}
	return 0;
}