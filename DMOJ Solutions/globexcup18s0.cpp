#include <bits/stdc++.h>
using namespace std;
#define int long long

/*

*/

const int nax = 1e5 + 5;
int n,x[nax],y[nax];

int f(int pos, int arr[]){
	int s = 0;
	for (int i = 0; i < n; ++i){
		s += abs(arr[i] - pos);
	}
	return s;
}

int ts(int arr[]){
	int lo = 0, hi = 1e9;
	while (hi - lo >= 3){
		int third = (hi - lo) / 3;
		int m1 = lo + third;
		int m2 = hi - third;
		if (f(m1,arr) <= f(m2,arr)){
			hi = m2 - 1;
		}
		else lo = m1 + 1;
	}
	int best = LLONG_MAX;
	for (int i = lo; i <= hi; ++i){
		best = min(best,f(i,arr));
	}
	return best;
}


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
	}
	int xans = ts(x);
	int yans = ts(y);
	cout << xans + yans << "\n";	
	return 0;
}