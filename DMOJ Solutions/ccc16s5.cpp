#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5, maxbit = ceil(log2(1e15));
int n,t;
int a[nax], temp[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) a[i] = s[i] - '0', temp[i] = a[i];
	for (int i = 0; i < maxbit; ++i){
		int num = (1ll << i);
		if (t & num){
			for (int i = 0; i < n; ++i){
				a[i] = temp[((i - num) % n + n) % n] ^ temp[(i + num) % n];
			}
			for (int i = 0; i < n; ++i){
				temp[i] = a[i];
			}
		}
	}
	for (int i = 0; i < n; ++i) cout << a[i];
	cout << "\n";	
	return 0;
}