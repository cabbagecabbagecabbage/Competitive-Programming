#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e0 + 5;


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x; cin >> x;
	if (x >= 90) cout << "expert";
	else if (x >= 70) cout << 90 - x;
	else if (x >= 40) cout << 70 - x;
	else cout << 40 - x;
	cout << "\n";
	
	return 0;
}