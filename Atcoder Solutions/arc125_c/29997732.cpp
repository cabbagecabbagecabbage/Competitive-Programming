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
	int n,k; cin >> n >> k;
	vector<int> used(n+1),a(n);
	for (int i = 0; i < k; ++i){
		cin >> a[i];
		used[a[i]] = 1;
	}
	vector<int> remaining;
	for (int i = n; i >= 1; --i){
		if (!used[i]) remaining.emplace_back(i);
	}
	for (int i = 0; i < k-1; ++i){
		sp(a[i]);
		if (!remaining.empty() and a[i] < remaining.back()) continue;
		if (remaining.size()){
			sp(remaining.back());
			remaining.pop_back();
		}
	}
	remaining.push_back(a[k-1]);
	sort(remaining.begin(),remaining.end());
	for (int i = remaining.size()-1; i >= 0; --i){
		sp(remaining[i]);
	}
	return 0;
}