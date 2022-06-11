#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int n,t; cin >> n >> t;
	while (t--){
		if (n % 2) cout << "1\n" << n/2 + 1 << " " << n/2 + 1 << "\n";
		else cout << "2\n";
		int x,y; cin >> x >> y;
		assert(x != -1 and y != -1);
		while (x != 0 and y != 0){
			cout << n-x+1 << " " << n-y+1 << "\n";
			cin >> x >> y;
			assert(x != -1 and y != -1);
		}
	}
	return 0;
}