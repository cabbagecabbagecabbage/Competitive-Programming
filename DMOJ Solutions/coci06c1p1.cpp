#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	unordered_set<int> s;
	for (int i = 0; i < 10; ++i){
		int a; cin >> a;
		s.insert(a%42);
	}
	cout << s.size() << "\n";
	return 0;
}