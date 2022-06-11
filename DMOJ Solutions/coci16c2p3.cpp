#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	int n; cin >> n;
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int l = 0, r = n-1; l < r;){
		if (a[l] == a[r]){
			++l; --r;
		}
		else if (a[l] < a[r]){
			a[l+1] += a[l];
			++l; ++ans;
		}
		else if (a[l] > a[r]){
			a[r-1] += a[r];
			--r; ++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}