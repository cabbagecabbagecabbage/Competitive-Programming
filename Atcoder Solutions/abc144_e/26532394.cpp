#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
sort the members by increasing a_i
sort the foods by decreasing f_i
how many sets of training is necessary for the team to finish the food in some given time t?
f(t) = 
a_i * f_i > t
	adjustment needed -> t / f_i
iterate thru all members and sum up t/f_i
if the total <= k then t is valid -> search for smaller t
otherwise invalid -> search for bigger t
*/

const int nax = 2e5 + 5;
ll n,k,a[nax],f[nax];

ll fn(ll t){
	ll training = 0;
	for (int i = 0; i < n; ++i){
		ll product = a[i] * f[i];
		if (product > t){
			//a[i]*f[i]>t (a[i] - m)*f[i] <= t	a[i] - m <= t/f[i]		m >= a[i] - t/f[i]
			training += a[i] - t/f[i];
		}
	}
	return training;
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
			//enough time, search for lower
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << "\n";	
	return 0;
}