#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
typedef vector<int> vi;

double dp[3001][3001];//dp[i][j] => the probability of exactly j heads in the first i coins

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    
	int n;
	cin >> n;
	double pcoin;
	dp[0][0] = 1;
	for (int i=1; i<=n; i++){
		cin >> pcoin;
		for (int j=0; j<=i; j++){
			if (j==0){
				dp[i][j] = dp[i-1][j]*(1-pcoin);
			}
			else{
				dp[i][j] = dp[i-1][j-1]*(pcoin) + dp[i-1][j]*(1-pcoin);
			}
		}
	}
	double ans=0;
	f2(1,n+1){
		if (2*i>n){
			ans += dp[n][i];
		}
	}
	cout << setprecision(12);
	cout << ans << "\n";
	return 0;
}