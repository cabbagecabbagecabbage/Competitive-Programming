#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;
long long n;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string ans = "";
	while (n > 0){
		if (n % 2 == 1){
			ans += "A";
			n--;
		}
		else {
			ans += "B";
			n /= 2;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	
	return 0;
}