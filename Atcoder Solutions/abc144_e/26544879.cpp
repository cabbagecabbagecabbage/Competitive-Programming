#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
sort a in non-decreasing order
sort f in non-increasing order
how many sets of training is necessary for the team to finish the food in t seconds?
fn(t)
for each member a[i] * f[i]
a[i] * f[i] > t
	(a[i]-m) * f[i] <= t
	a[i] - m <= t/f[i]
	m >= a[i] - t/f[i]
	m = a[i] - t/f[i]
fn(t) would be the total of all m for each member

fn(t) > k then we can't finish in t minutes with k sets of training
fn(t) <= k then we can finish
*/

const int nax = 2e5 + 5;
ll n,k,a[nax],f[nax];

ll fn(ll t){
	ll total = 0;
	for (int i = 0; i < n; ++i){
		if (a[i] * f[i] > t){
			//cant finish in time, need training
			total += (a[i] - t/f[i]);
		}
	}
	return total;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> f[i];
	sort(a,a+n);
	sort(f,f+n,greater<ll>());
	ll lo = 0, hi = 1e12;
	ll ans;
	while (lo <= hi){
		ll mid = (lo + hi) / 2;
		if (fn(mid) <= k){
			hi = mid - 1;
			ans = mid;
		}
		else lo = mid + 1;
	}
	cout << ans << "\n";
	
	return 0;
}