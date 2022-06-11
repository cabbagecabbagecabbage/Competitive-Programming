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
typedef vector<int> vi;
typedef pair<int, int> pii;

/*
must walk at least n-1 down and n-1 right in total
we only need to keep track of the number of left moves needed
dp[r][c] store the minimum number of lefts needed. fill with inf at first
for every row after the first make 2 passes:
going from left to right:
	if the current cell is walkable:
		dp[current] = min(dp[above],dp[left])
going from right to left:
	if the current cell is walkable:
		dp[current] = min(current,right+1)

*/

int grid[1005][1005]; // 1 if walkable, 0 if not
int dp[1005][1005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string row;
	f(n){
		cin >> row;
		ff(n){
			if (row[j]=='.') grid[i+1][j+1] = 1;
		}
	}
	mem(dp,0x3f);
	dp[1][0] = 0;
	f2(1,n+1){
		//for each row
		
		//going from left to right
		ff2(1,n+1){
			if (grid[i][j]) dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
		}
		
		//going from right to left
		for (int j = n; j>=1; j--){
			if (grid[i][j]) dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
		}
	}
	if (dp[n][n] == 0x3f3f3f3f){
		cout << -1 << endl;
		return 0;
	}
	long long left = dp[n][n];
	long long down = n-1;
	long long right = n-1+left;
	cout << left*left + down*down + right*right << endl;

  return 0;
}