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
typedef pair<int, int> pii;

/*
first precalculate the distance between every pair of nodes (floyd warshall) if no intermediate nodes are used. this would be the answer if the number of days was 1.

then for d=2, for every node, try to use this node as an intermediate node for every pair of nodes. the minimum for any pair of nodes is the minimum of all the maximums between the 2 sections (reaching from the start to the intermediate, then from the intermediate to the end)

in general, from node j to node k in d days, we need to take the minimum between all the maximums between the minimum distance travelled on the first d-1 days from j to i, and the distance travelled on the last day going from i to k, for every intermediate node i.
*/
int n,q;
long long inf = 0x3f3f3f3f3f3f3f3f;
long long dp[105][105][105]; //stores [days][i][j] aka the answer the query f(i-1,j-1,d-1)
// int matrix[105][105];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	mem(dp,0x3f);
	f(n) {
		ff(n) {
			cin >> dp[0][i][j];
			if (i==j) dp[0][i][j] = 0;
			elif (dp[0][i][j]==0) dp[0][i][j] = inf;
		}
	}
	//calculate for 1 day
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[0][i][j] = min(dp[0][i][j], (dp[0][i][k] + dp[0][k][j]));
			}
		}
	}

	//do for the rest of the days
	for (int day = 1; day < n; day++){
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dp[day][i][j] = min(dp[day][i][j], max(dp[day-1][i][k],dp[0][k][j]));
				}
			}
		}
	}

	cin >> q;
	int s,t,d;
	f(q){
		cin >> s >> t >> d;
		long long ans = dp[d-1][s-1][t-1];
		if (ans!=inf) cout << ans << endl;
		else cout << 0 << endl;
	}

	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}