#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
https://dmoj.ca/problem/art5/editorial

i copied the following text to understand it

The state is dp[i][j], which represents the minimum cost to catch the first i paintings where the resting person most recently caught the jth painting.

Transitions:

dp[i][j] = min(dp[i][j],dp[i−1][j]+dist(i−1,i))
where the resting person who is at j does not change/move, while the active person goes from i-1 to i incurring a cost of dist(i-1,i)

dp[i][i−1] = min(dp[i][i−1],dp[i−1][j]+dist(j,i))
where we force the person at j to go from j to i incurring a cost of dist(j,i) and the person resting is now the person who is at i-1

let him and his assistant be A,B respectively

we plug their coordinates into the array
*/

pii arr[2005];
int dp[2005][2005];

int dist(int a, int b){
	int x1 = arr[a].first;
	int y1 = arr[a].second;
	int x2 = arr[b].first;
	int y2 = arr[b].second;
	return abs(x1-x2) + abs(y1-y2);
}

int n;
int hx, hy, ax, ay;
int x,y;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	cin >> hx >> hy >> ax >> ay;
	mem(dp,0x3f);
	f(n){
		cin >> x >> y;
		arr[i+2] = mp(x,y);
	}
	int firstdist = abs(arr[2].first-hx) + abs(arr[2].second-hy);
	int seconddist = abs(arr[2].first-ax) + abs(arr[2].second-ay);

	arr[0] = mp(ax,ay);
	arr[1] = mp(hx,hy);
	dp[2][0] = firstdist;
	dp[2][1] = seconddist;


	f2(1,n+2){
		ff(n+2){
			dp[i][j] = min(dp[i][j],dp[i-1][j]+dist(i-1,i)); //let the active guy get it
			dp[i][i-1] = min(dp[i][i-1],dp[i-1][j]+dist(j,i)); //let the resting guy get it
		}
	}
	int ans = INT_MAX;
	f(n+2){
		ans = min(ans,dp[n+1][i]);
	}
	cout << ans << endl;
	return 0;
}