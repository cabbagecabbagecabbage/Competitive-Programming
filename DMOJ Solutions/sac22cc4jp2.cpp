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
	int n = read(), q = read();
	vector<int> v(n+1); // 0 r, 1 sq, 2 circle, 3 triangle
	unordered_map<string,int> m = {{"square",1},{"circle",2},{"triangle",3}};
	while (q--){
		string a,b; int c;
		cin >> a >> b >> c;
		if (a == "get"){
			out(m[b] == v[c]);
		}
		else {
			v[c] = m[b];
		}
	}
	
	return 0;
}