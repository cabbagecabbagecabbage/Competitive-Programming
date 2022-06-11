#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

const int nax = 1e3 + 5;
const int mod = 1e9 + 7;

int grid[nax][nax];
int dp[nax][nax];
int h,w;
string row;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> h >> w;

	dp[1][0] = 1; //offset to the left bc 1,1 can take from 0,1
	for (int i = 1; i <= h; i++){
		cin >> row;
		for (int j = 1; j <= w; j++){
			if (row[j-1] != '#') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
		}
	}
	cout << dp[h][w] << endl;	
	
	return 0;
}




















//trailing lines ftw