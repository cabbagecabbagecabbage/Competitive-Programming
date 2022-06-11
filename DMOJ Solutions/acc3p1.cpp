#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define scan(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;
long long n;
int k,a[maxn],freq[maxn];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scan(n); scan(k);
	long long ans = n * (n+1) / 2;
	for (int i = 0; i < n; ++i){
		scan(a[i]);
	}
	int left = -1, cnt = 0;
	for (int i = 0; i < n; ++i){
		if (freq[a[i]]++ == 0) ++cnt;
		while (cnt >= k) if (freq[a[++left]]-- == 1) --cnt;
		ans -= i - left;
	}
	cout << ans << "\n";
	return 0;
}