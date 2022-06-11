#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int arr[100005],dp[100005][10];

main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	dp[0][arr[0]] = 1; 	
	for (int i = 0; i < n-1; ++i){
		for (int dig = 0; dig < 10; ++dig){
			dp[i+1][(dig + arr[i+1]) % 10] += dp[i][dig];
			dp[i+1][(dig + arr[i+1]) % 10] %= mod;
			dp[i+1][(dig * arr[i+1]) % 10] += dp[i][dig];
			dp[i+1][(dig * arr[i+1]) % 10] %= mod;
		}
	}
	for (int dig = 0; dig < 10; ++dig){
		cout << dp[n-1][dig] << "\n";
	}
	return 0;
}