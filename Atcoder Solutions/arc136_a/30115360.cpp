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
	int n; string s; cin >> n >> s;
	string ans;
	for (char c: s){
		if (c == 'A') ans += "BB";
		else ans += c;
	}
	ans += "$";
	string ans1;
	for (int i = 0; i < ans.length()-1; ++i){
		if (ans[i] == 'C' or ans[i+1] != 'B') ans1 += ans[i];
		else ans1 += 'A', ++i;
	}
	out(ans1);
	return 0;
}