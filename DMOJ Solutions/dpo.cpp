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

int grid[25][25];
int dp[25][2097152];
//dp[i][mask] = number of pairs with first i men with the subset of women (represented by mask)

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    int n;
    cin >> n;
    f2(1,n+1){
    	ff(n){
    		cin >> grid[i][j];
    	}
    }

    dp[0][0] = 1;
    int mod = 1e9+7;
    for (int i=1; i<n+1; i++){
    	//the first i men
    	for (int mask=0; mask<(1<<n); mask++){
    		//for every subset of women (mask represents subset)
    		if (__builtin_popcount(mask)==i){
    			//if there are same number of men and women (cant pair up if not the same)
    			for (int woman=0; woman<n; woman++){
    				if ((1<<woman)&mask){
    					//go thru every woman in the subset
    					if (grid[i][woman]){
    						//if we can pair up the i-th man and a woman in the subset
    						dp[i][mask] += dp[i-1][mask-(1<<woman)]; //mask-(1<<woman) removed the woman from the subset
    						//we add all the possibilities that excludes the man and woman, since now we know the first i men and the subset of women can be paired up
    						dp[i][mask]%=mod;
    					}
    				}
    			}
    		}
    		// cout << dp[i][mask] << " ";
    	}
    	// n()
    }
    cout << dp[n][(1<<n)-1];n()

	return 0;
}