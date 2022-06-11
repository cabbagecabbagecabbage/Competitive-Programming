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

vi coins;
long long dp[3001][3001];
//dp[i][j] stores maximum difference at interval [i,j], regardless of who gets to the state
//transition: dp[i][j] = max(coins[i]-dp[i+1][j],coins[j]-dp[i][j-1])
//when u take left, subtract by the max that ur opponent can win by in the next state, and vice versa

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	int n,k;
	cin >> n;
	f(n){
		cin >> k;
		coins.push_back(k);
	}

	/*algo trace
	4
	10 80 90 30

	loop:
	dp[3][3] = 30
	dp[2][2] = 90
	dp[2][3] = max(coins[2]-dp[3][3],coins[3]-dp[2][2]) = 60
	dp[1][1] = 80
	dp[1][2] = max(coins[1]-dp[2][2],coins[2]-dp[1][1]) = 10
	dp[1][3] = max(coins[1]-dp[2][3],coins[3]-dp[1][2]) = 20
	dp[0][0] = 10
	dp[0][1] = max(coins[0]-dp[1][1],coins[1]-dp[1][1]) = 70
	dp[0][2] = max(coins[0]-dp[1][2],coins[2]-dp[0][1]) = 20
	dp[0][3] = max(coins[0]-dp[1][3],coins[3]-dp[0][2]) = 10
	final answer: dp[0][n-1] = 10
    */
    fb(n){
    	ff2(i,n){
    		if (i==j){
    			dp[i][j] = coins[i];
    		}
    		else dp[i][j] = max(coins[i]-dp[i+1][j],coins[j]-dp[i][j-1]);
    	}
    }
    cout << dp[0][n-1] << "\n";
	return 0;
}