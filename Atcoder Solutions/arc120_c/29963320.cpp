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
	int n; cin >> n;
	vector<pii> a(n),b(n);
	vector<int> s(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].first += a[i].second = i;
	}
	for (int i = 0; i < n; ++i){
		cin >> b[i].first;
		b[i].first += b[i].second = i;
	}
	sort(a.begin(),a.end()); sort(b.begin(),b.end());
	for (int i = 0; i < n; ++i){
		if (a[i].first != b[i].first){
			out(-1);
			return 0;
		}
		s[a[i].second] = b[i].second;
	}
	int ans = 0;
	vector<int> tree(2*n);
	for (int i = n-1; i >= 0; --i){
		for (int l = 0 + n, r = s[i] + n + 1; l < r; l /= 2, r /= 2){
			if (l%2){
				ans += tree[l++];
			}
			if (r%2){
				ans += tree[--r];
			}
		}
		int pos = s[i];
		for (tree[pos+=n] = 1; pos /= 2;){
			tree[pos] = tree[pos*2] + tree[pos*2+1];
		}
	}
	out(ans);
	return 0;
}