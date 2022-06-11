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
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*

state:

dp[i][j][k] stores the number of ways to pick the first i digits with:

j = 0 indicates that there are no 1's yet
j = 1 indicates that there is a 1 already but there is no 0 after the 1 yet
j = 2 indicates that the subsequence is completed and dont add any more 0's

throughout the transitions we go from
no sub -> 1 sub -> 10 sub

we have also to consider whether we are "free": whether we have chosen a digit that is less than the corresponding digit at k already, which determines what digits we can add to our sequence

k = 0 	means current state not free
if we want next state to be free we have to choose any digit less than digit[i]
if we want next state to still be not free we can choose digit[i]

k = 1	means we are free
theres no way to go back. we can use any digit

transitions: (some of these transitions might not be possible depending on the current digit)
let current digit = curdig

no sub, not free -> no sub, not free 	(cant pick 1, pick curdig)
no sub, not free -> no sub, free 		(cant pick 1, pick less than curdig)
no sub, not free -> 1 sub, not free 	(pick 1, pick curdig) (only if curdig == 1)
no sub, not free -> 1 sub, free 		(pick 1, pick less than curdig)
no sub, free -> no sub, free			(dont pick 1)
no sub, free -> sub, free 				(pick 1)

1 sub, not free -> 1 sub, not free		(dont pick 0, pick curdig)
1 sub, not free -> 1 sub, free			(pick less than curdig, dont pick 0)
1 sub, free -> 1 sub, free				(dont pick 0)
1 sub, not free -> 10 sub, free			(pick 1, pick less than curdig)
1 sub, not free -> 10 sub, not free		(pick 0, pick curdig) (only if curdig == 0)
1 sub, free -> 10 sub, free				(pick 0)

10 sub, not free -> 10 sub, not free	(dont pick 0, pick curdig)
10 sub, not free -> 10 sub, free		(dont pick 0, pick less than curdig)
10 sub, free -> 10 sub, free			(dont pick 0)

*/

long long dp[100005][4][3];

int digit[100005];
	
const int mod = 1e9 + 7;

void adds(long long& a, long long b){
	a += b;
	if (a >= mod) a-= mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n = 0;
	char c;
	while ((c = getchar()) >= '0'){
		digit[n] = c-'0';
		n++;
	}
	//base case
	dp[0][0][0] = 1;
	f(n){
		int curdig = digit[i];
		//j = 0, 1, 2
		//k = 0, 1
		int mul;
		
		// no sub, not free -> no sub, not free 	(dont pick 1, pick curdig)
		if (curdig == 1) mul = 0; else mul = 1;
		adds(dp[i+1][0][0], dp[i][0][0]*mul % mod);
		// no sub, not free -> no sub, free 		(dont pick 1, pick less than curdig)
		if (curdig == 1) mul = 1; else mul = max(curdig - 1, 0);
		adds(dp[i+1][0][1], dp[i][0][0]*mul % mod);
		// no sub, not free -> 1 sub, not free 		(pick 1, pick curdig) (only if curdig == 1)
		if (curdig == 1) adds(dp[i+1][1][0],dp[i][0][0]);
		// no sub, not free -> 1 sub, free 			(pick 1, pick less than curdig)
		if (curdig > 1) adds(dp[i+1][1][1], dp[i][0][0]);
		// no sub, free -> no sub, free				(dont pick 1)
		adds(dp[i+1][0][1], dp[i][0][1]*9 % mod);
		// no sub, free -> sub, free 				(pick 1)
		adds(dp[i+1][1][1], dp[i][0][1]);
		
	
		// 1 sub, not free -> 1 sub, not free		(dont pick 0, pick curdig)
		if (curdig != 0) adds(dp[i+1][1][0], dp[i][1][0]);
		// 1 sub, not free -> 1 sub, free			(pick less than curdig, dont pick 0)
		if (curdig > 0) adds(dp[i+1][1][1], dp[i][1][0]*(curdig-1) % mod);
		// 1 sub, free -> 1 sub, free				(dont pick 0)
		adds(dp[i+1][1][1], dp[i][1][1]*9 % mod);
		// 1 sub, not free -> 10 sub, free			(pick 0, pick less than curdig)
		if (curdig != 0) adds(dp[i+1][2][1], dp[i][1][0]);
		// 1 sub, not free -> 10 sub, not free		(pick 0, pick curdig) (only if curdig == 0)
		if (curdig == 0) adds(dp[i+1][2][0], dp[i][1][0]);
		// 1 sub, free -> 10 sub, free				(pick 0)
		adds(dp[i+1][2][1], dp[i][1][1]);
	
	
		// 10 sub, not free -> 10 sub, not free		(dont pick 0, pick curdig)
		if (curdig != 0) adds(dp[i+1][2][0], dp[i][2][0]);
		// 10 sub, not free -> 10 sub, free			(dont pick 0, pick less than curdig)
		if (curdig > 1) adds(dp[i+1][2][1], dp[i][2][0]*(curdig-1) % mod);
		// 10 sub, free -> 10 sub, free				(dont pick 0)
		adds(dp[i+1][2][1], dp[i][2][1]*9 % mod);
	}

	cout << (dp[n][2][0] + dp[n][2][1]) % mod << endl;
	return 0;
}




















//trailing lines ftw