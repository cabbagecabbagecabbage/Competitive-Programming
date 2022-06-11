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
	cin.tie(0)->sync_with_stdio(0);
	int t = read();
	while (t--){
		int a = read(), b = read(), c = read(), d = read();
		b -= a;
		d -= c;
		swap(c,d);
		b *= c;
		d *= a;
		if (b > d) out("YES");
		else out("NO");
	}
	return 0;
}