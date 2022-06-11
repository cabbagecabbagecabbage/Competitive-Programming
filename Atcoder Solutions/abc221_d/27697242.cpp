#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans[200005];
pair<int,int> arr[400005];
int32_t main(){
	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; ++i){
		int a,b; cin >> a >> b;
		b += a;
		arr[idx++] = {a,1};
		arr[idx++] = {b,-1};
	}
	sort(arr,arr+idx);
	int players = 0;
	int prevday = arr[0].first;
	for (int i = 0; i < idx; ++i){
		// cout << players << " " << arr[i].first << " " << prevday << "\n";
		ans[players] += arr[i].first - prevday;
		prevday = arr[i].first;
		players += arr[i].second;		
	}
	for (int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}