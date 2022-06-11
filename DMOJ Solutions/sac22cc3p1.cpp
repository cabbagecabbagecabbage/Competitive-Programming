#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int h,s,q; cin >> h >> s >> q;
	while (q--){
		h -= s;
		cout << h << "\n";
	}
	return 0;
}