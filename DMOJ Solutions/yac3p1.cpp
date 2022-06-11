#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
int ri(){int x; cin >> x; return x;}
vi rv(int l){vi v(l);generate(all(v),ri);return v;}

#define local
#ifdef local
	template<typename T>void out(T x){cout<<x<<"\n";}
	template<typename T>void sp(T x){cout<<x<<" ";}
	template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
	template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}
	#define var(x) cout<<#x<<": "<<x<<"\n"
#else
	#define out
	#define var
#endif

const int mod = 1000000007, inf = 0x3f3f3f3f3f3f3f3f;

/*

*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n = ri(), m = ri(), a = ri(), b = ri();
	vector<pii> swaps(m+1);
	for (int i = 0; i < m; ++i){
		int x = ri();
		if (x == -1) swaps[i] = {-1,-1};
		else {
			int y = ri();
			swaps[i] = {x,y};
		}
	}
	int start = a, end = b;
	int idx=m-1;
	for (int i = m-1; swaps[i].first != -1; --i){
		assert(i >= 0);
		if (swaps[i].first == end){
			end = swaps[i].second;
		}
		else if (swaps[i].second == end){
			end = swaps[i].first;
		}
		idx = i-1;
	}
	// out(end);
	for (int i = 0; i < idx; ++i){
		if (swaps[i].first == -1) swaps[i] = {1,2};
		if (swaps[i].first == start){
			start = swaps[i].second;
		}
		else if (swaps[i].second == start){
			start = swaps[i].first;
		}
	}
	// out(start);
	assert(0 <= idx and idx <= m-1);
	if (start == end){
		if (start == 1) swaps[idx] = {2,3};
		else if (start == n) swaps[idx] = {n-2,n-1};
		else swaps[idx] = {start+1,start-1};
	}
	else swaps[idx] = {start,end};
	for (int i = 0; i < m; ++i){
		out(swaps[i].first,swaps[i].second);
	}
	return 0;
}