#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
	int k,a,b; cin >> k >> a >> b;
	int da = 0, db = 0;
	int tk = 1;
	while (a){
		da += (a % 10) * tk;
		tk *= k;
		a /= 10;
	}
	tk = 1;
	while (b){
		db += (b % 10) * tk;
		tk *= k;
		b /= 10;
	}
	cout << da * db << "\n";
	return 0;
}