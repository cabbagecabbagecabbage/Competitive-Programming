#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	int len = 0;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		a[i] = stoi(s);
		len = max(len,(int) s.length());
	}
	int mod = 1;
	for (int i = 1; i <= len; ++i){
		mod *= 10;
		vector<int> b(n);
		for (int j = 0; j < n; ++j) b[j] = j;
		sort(b.begin(),b.end(),[&](int x, int y){
			return a[x] % mod < a[y] % mod;
		});
		for (int j = 0; j < n; ++j){
			cout << a[b[j]] << " \n"[j == n-1];
		}
	}
	return 0;
}