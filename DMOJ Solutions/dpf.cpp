#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

int dp[3002][3002];
string a,b;


int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    cin >> a >> b;
    int al = a.size();
    int bl = b.size();

    f2(1,al+1){
    	ff2(1,bl+1){
    		if (a[i-1]==b[j-1]){
    			dp[i][j] = dp[i-1][j-1]+1;
    			continue;
    		}
    		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    	}
    }
    // f(al+1){
    // 	ff(bl+1){
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }
    string ans;
    int cury = al, curx = bl;
    while (cury>0 && curx>0){
    	if (dp[cury][curx] == 1+dp[cury-1][curx-1] && dp[cury][curx]>dp[cury][curx-1] && dp[cury][curx]>dp[cury-1][curx]){
    		ans = a[cury-1] + ans;
    		cury--;curx--;
    	}
    	elif (dp[cury][curx-1] > dp[cury-1][curx]){
    		curx--;
    	}
    	else{
    		cury--;
    	}
    }
    cout << ans << "\n";
	return 0;
}