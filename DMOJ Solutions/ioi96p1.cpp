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
long long dp[101][101];
int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	int n,k;
	int sum=0;
	cin >> n;
	f(n){
		cin >> k;
		coins.push_back(k);
		sum += k;
	}
    fb(n){
    	ff2(i,n){
    		if (i==j){
    			dp[i][j] = coins[i];
    		}
    		else dp[i][j] = max(coins[i]-dp[i+1][j],coins[j]-dp[i][j-1]);
    	}
    }
    int p1 = (sum + dp[0][n-1]) / 2;
    int p2 = sum-p1;
    cout << p1 << " " << p2 << "\n";
	return 0;
}