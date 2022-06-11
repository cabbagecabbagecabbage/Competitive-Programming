#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int read(){int x; cin >> x; return x;}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	// cin.tie(0)->sync_with_stdio(0);
	int n = read();
	vector<int> ans(n+1,-1);
	int half = n/2;
	cout << "? " << 1 << " " << n << "\n";
	int a = read();
	int b = 0;
	for (int i = 1; i <= half; ++i){
		assert(i+1 < n);
		cout << "? " << i+1 << " " << n << "\n";
		int suf = read();
		assert(suf != -1);
		ans[i] = a ^ b ^ suf;
		b ^= ans[i];
	}
	int c = 0;
	for (int i = n; i > half + 1; --i){
		assert(1 < i-1);
		cout << "? " << 1 << " " << i-1 << "\n";
		int pre = read();
		assert(pre != -1);
		ans[i] = a ^ c ^ pre;
		c ^= ans[i];
	}
	ans[half+1] = a ^ b ^ c;
	ans.erase(ans.begin());
	cout << "! ";
	for (int i = 0; i < ans.size(); ++i){
		assert(ans[i] != -1);
		cout << ans[i] << " \n"[i == ans.size()-1];
	}
	return 0;
}