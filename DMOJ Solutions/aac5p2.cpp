#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,_min = INT_MAX, _max = INT_MIN,ans[100005];
int32_t main(){
	cin >> n;
	assert(n >= 3);
	for (int i = 2; i <= n; ++i){
		cout << "? 1 " << i << "\n" << flush;
		cin >> ans[i];
		assert(ans[i] != -1);
		_min = min(_min,ans[i]);
		_max = max(_max,ans[i]);
	}
	ans[1] = _max == n ? 1 : _min;
	cout << "! " << ans[1];
	for (int i = 2; i <= n; ++i) cout << " " << ans[i] / ans[1];
	cout << "\n";
	cout << flush;
	return 0;
}