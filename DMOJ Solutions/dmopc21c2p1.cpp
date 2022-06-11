#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tree<pair<ll,ll>,null_type,greater<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> ost;
/*

*/

const int nax = 1e6 + 5;
ll n,h,p,a[nax];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> h >> p;
	ll sum = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		ost.insert({a[i],i});
		sum += a[i];
	}
	sum *= p;
	ll curp = 0, ans = sum;
	for (int i = 0; i < n; ++i){
		while (true){
			int greatercnt = ost.order_of_key({curp+1,-1});
			if (h + ans - p*greatercnt < ans){
				ans = h + ans - p*greatercnt;
				++curp;
			}
			else {
				break;
			}
		}
		sum -= a[i];
		ost.erase({a[i],i});
	}
	cout << ans << "\n";
	
	return 0;
}