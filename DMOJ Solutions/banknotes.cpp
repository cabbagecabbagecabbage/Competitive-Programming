#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1e9 + 7, inf = 0x3f3f3f3f3f3f3f3f;



signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> b(n),c(n);
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	int k; cin >> k;
	vector<int> dp(k+1,inf);
	dp[0] = 0;
	for (int i = 0; i < n; ++i){
		for (int m = 1; c[i] > 0; m *= 2){
			if (m > c[i]) m = c[i];
			c[i] -= m;
			for (int j = k; j >= m*b[i]; --j){
				dp[j] = min(dp[j],dp[j-m*b[i]] + m);
			}
		}
	}
	cout << dp[k] << "\n";
	return 0;
}