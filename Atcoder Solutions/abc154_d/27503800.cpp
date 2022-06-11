#include <bits/stdc++.h>
using namespace std;

int n,k;
long double a[200005];

int main(){
	cin >> n >> k;
	long double ans = 0, sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		sum += (1+a[i])/2;
		++cnt;
		if (cnt > k){
			sum -= (1+a[i-k])/2;
		}
		ans = max(sum,ans);
	}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}