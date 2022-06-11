#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int l = 0; l < a; l++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int l = a; l < b; l++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*

*/

const int nax = 2e3 + 5;
pii sugar[nax];
int n, dp[2][nax][nax], prefix[nax];
#define x first
#define d second

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f2(1,n+1) in2(sugar[i].x,sugar[i].d);
	sort(sugar + 1, sugar + n + 1);
	mem(dp,-1);
	f2(1,n+1){
		prefix[i] = prefix[i-1] + sugar[i].d;
		if (sugar[i].x == 0){
			//if they dont entend from 0, dont give them a base case
			dp[0][i][i] = dp[1][i][i] = sugar[i].d;
		}
	}
	for(int i=1; i<n; i++){
        for(int l=1; l+i <= n; l++){
            int r = l+i;
            //the state we want to update is dp[0/1][l][r]
            
            //first we update dp[0][l][r] by extending the interval from the right 
            //and going to the left, therefore being on the left side of the interval
            //the state on the right of us is dp[0/1][l+1][r]
            //however, if we come from the other end of the interval (dp[1][l+1][r]), then we
            //incur a cost of running thru the entire interval between [l+1,r] again
            //we take the max of these, and try to update the current state
            //see if we had enough energy to continue running from l+1 -> l
            //if so, we take the previous max, subtract the distance from l+1 -> l, and
            //add the sugar we get on l
            int fromleft, fromright, best, dist;
            
            fromleft = dp[0][l+1][r];
            fromright = dp[1][l+1][r] - (sugar[r].x - sugar[l+1].x);
            best = max(fromleft,fromright);
            dist = sugar[l+1].x - sugar[l].x;
            if (best >= dist) dp[0][l][r] = max(dp[0][l][r],best - dist + sugar[l].d);
            
            //similar but reversed logic for dp[1][l][r]
            fromleft = dp[0][l][r-1] - (sugar[r-1].x - sugar[l].x);
            fromright = dp[1][l][r-1];
            best = max(fromleft,fromright);
            dist = sugar[r].x - sugar[r-1].x;
            if (best >= dist) dp[1][l][r] = max(dp[1][l][r],best - dist + sugar[r].d);
            
        }
    }
    
    int ans = 0;
    
    for(int l=1; l<=n; l++){
        for(int r=l; r<=n; r++){
        	if (dp[0][l][r] != -1 || dp[1][l][r] != -1){
        		ans = max(ans,prefix[r] - prefix[l-1]);
        	}
        }
    }
    
    out(ans);
    		

	return 0;
}




















//trailing lines ftw