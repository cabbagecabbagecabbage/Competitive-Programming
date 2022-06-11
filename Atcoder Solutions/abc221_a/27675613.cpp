#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int a,b; cin >> a >> b;
	int diff = a - b;
	int ans = 1;
	while (diff--){
		ans *= 32;
	}
	cout << ans;
	return 0;
}