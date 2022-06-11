#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[100005];
main(){
	int n; cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
		s += arr[i];
	}
	int x; cin >> x;
	int ans = x / s * n;
	x %= s;
	for (int i = 0; i < n; ++i){
		if (x < 0) break;
		x -= arr[i];
		++ans;
	}
	cout << ans << "\n";
	return 0;
}