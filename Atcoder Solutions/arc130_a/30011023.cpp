#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	string s; cin >> s;
	int pre = 0, ans = 0;
	s += '$';
	for (int i = 1; i <= n; ++i){
		if (s[i] != s[i-1]){
			int len = i - pre;
			pre = i;
			ans += (len-1)*len / 2;
		}
	}
	out(ans);
	return 0;
}