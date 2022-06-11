#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;

int dp[152][305][102]; //dp[k][i][j] stores the maximum impression value using the first k restaurants with a total of i time and j units of food consumed
int impv[200];
int ti[200];
int food[200];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int m,u,r;
	cin >> m >> u >> r;
	f2(1,r+1){
		cin >> impv[i] >> ti[i] >> food[i];
	}
	for (int k=1; k <= r; k++){
		f(m+1){
			ff(u+1){
				if (i-ti[k]>-1 && j-food[k]>-1){
					dp[k][i][j] = max(dp[k-1][i][j],dp[k-1][i-ti[k]][j-food[k]]+impv[k]);
				}
				else dp[k][i][j] = dp[k-1][i][j];
			}
		}
	}
	cout << dp[r][m][u] << endl;
    

 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}