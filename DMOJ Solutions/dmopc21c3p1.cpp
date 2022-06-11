#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans[100005];

int32_t main(){
	int n; cin >> n;
	for (int i = 1; i+1 <= n; i += 2){
		cout << "?" << " " << i << " " << i+1 << "\n";
		int aminusb; cin >> aminusb;
		cout << "?" << " " << i << " " << i+1 << "\n";
		int twob; cin >> twob;
		ans[i+1] = twob / 2;
		ans[i] = ans[i+1] + aminusb;
	}
	if (n % 2){
		cout << "?" << " " << n-1 << " " << n << "\n";
		int twobminusc; cin >> twobminusc;
		ans[n] = 2 * ans[n-1] - twobminusc;
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i){
		cout << ans[i] << " \n"[i == n];
	}
	return 0;
}