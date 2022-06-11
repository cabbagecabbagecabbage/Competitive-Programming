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
	vector<int> s(n+1),a(n+3),add(3);
	for (int i = 1; i <= n; ++i){
		cin >> s[i];
	}
	for (int i = 4; i <= n+2; ++i){
		a[i] = a[i-3] + s[i-2] - s[i-3];
	}
	// for (int i = 1; i <= n+2; ++i){
		// if (a[i] + add[i%3] < 0){
			// add[i%3] += abs(a[i]);
		// }
	// }
	// out(a);
	for (int i = 1; i <= n+2; ++i){
		if (a[i] < 0){
			add[i%3] = max(add[i%3],-a[i]);
		}
	}
	// out(add);
	for (int i = 1; i <= n+2; ++i){
		a[i] += add[i%3];
	}
	// out(a);
	int off = 0;
	if (a[1]+a[2]+a[3] < s[1]){
		off = s[1] - (a[1]+a[2]+a[3]);
	}
	for (int i = 1; i <= n+2; i += 3){
		a[i] += off;
	}
	for (int i = 1; i <= n; ++i){
		int sum = a[i] + a[i+1] + a[i+2];
		if (sum != s[i]){
			out("No");
			return 0;
		}
	}
	out("Yes");
	a.erase(a.begin());
	out(a);
	return 0;
}