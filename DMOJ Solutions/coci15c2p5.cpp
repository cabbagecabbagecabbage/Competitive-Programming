#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
using namespace std;
#define scan(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;

/*
query on index instead
*/

const int nax = 1e6 + 15;
int n,p;
int s[nax];
long long arr[nax];
pair<long long,int> prefix[nax]; //sum, idx pairs

void update(int pos) { // a[pos] += dif
	// pos += 10;
	for (; pos < n+1; pos |= pos + 1) ++s[pos];
}

int query(int pos) { // sum of values in [0, pos)
	// pos += 10;
	int res = 0;
	for (; pos > 0; pos &= pos - 1) res += s[pos-1];
	return res;
}

int32_t main() {
	scan(n);
	for (int i = 1; i <= n; ++i){
		scan(arr[i]);
	}
	scan(p);
	prefix[0] = {0,0};
	for (int i = 1; i <= n; ++i){
		arr[i] += arr[i-1] - p;
		prefix[i] = {arr[i],i};
	}
	sort(prefix, prefix+n+1);
	long long ans = 0;
	for (int i = 0; i <= n; ++i){
		ans += query(prefix[i].second);
		update(prefix[i].second);
	}
	cout << ans << "\n";
	return 0;
}