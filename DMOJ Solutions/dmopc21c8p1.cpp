#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
vi rv(int l){vi v(l);generate(all(v),ri);return v;}
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri(), m = ri();
	vi a = rv(n);
	multiset<int> s;
	for (auto k: a) s.insert(k);
	vi b;
	b.emplace_back(*s.begin());
	s.erase(s.begin());
	while (!s.empty()){
		int val = m - b.back();
		auto it = s.lower_bound(val);
		if (it == s.end()){
			out(-1);
			return 0;
		}
		b.emplace_back(*it);
		s.erase(it);
	}
	for (int i = 0; i < n; ++i){
		cout << b[i] << " \n"[i == n-1];
	}
	return 0;
}