#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1e9 + 7, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	//flip everything so a1 = 0
	if (a[0] != 0){
		for (int i = 0; i < n; ++i) a[i] = 1 - a[i];
		for (int i = 0; i < m; ++i) b[i] = 1 - b[i];
	}
	bool done = false;
	bool ptr = false; //true if last one was a 1
	int ans = 0;
	int mindist = inf;
	for (int i = 1; i < n; ++i) if (a[i] == 1) mindist = min(mindist,min(i, n - i));
	// out(mindist);
	for (int i = 0; i < m; ++i){
		if (b[i] == 1 and not done){
			if (mindist == inf){
				out(-1); return 0;
			}
			ans += mindist;
			done = true;
			ptr = true;
		}
		else if (ptr == b[i]) continue;
		else {
			ans += 1;
			ptr = !ptr;
		}
		// out(ans);
	}
	out(ans + m);
	return 0;
}