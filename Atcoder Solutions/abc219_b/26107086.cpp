#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 1e3 + 5;
string a[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string t; cin >> t;
	for (char c: t){
		if (c == '1'){
			cout << s1;
		}
		else if (c == '2'){
			cout << s2;
		}
		else cout << s3;
	}
	cout << "\n";
	return 0;
}