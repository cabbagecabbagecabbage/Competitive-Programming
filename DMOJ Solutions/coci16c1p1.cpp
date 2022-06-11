#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int x,n,p,cur; cin >> x >> n;
	cur = 0;
	for (int i = 0; i < n; ++i){
		cur += x;
		cin >> p;
		cur -= p;
	}
	cout << cur+x << "\n";
	return 0;
}