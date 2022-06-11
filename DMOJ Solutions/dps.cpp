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

int dp[10003][103][3];
//dp[i][j][restricted] stores the number of ways to obtain j mod D, restricted indicating whether the entire digitset can be used or just the ones smaller than or equal to k[i]
string k;
char num[10003];
int d;

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	cin >> k;
	int kl = k.length();
	int idx = 0;
	for (char c : k) {
		num[idx] = c;
		idx++;
	}
	cin >> d;
	int mod = 1e9 + 7;
	dp[0][0][1] = 1;
	f(kl) {
		//the first i positions
		ff(d) {
			//for every sum current sum

			//digit: the digit we can try to add on next
			int curdig = num[i] - '0'; //current digit

			for (int digit = 0; digit < 10; digit++) {
				//we can add on 0->9 if current position is already unrestricted
				dp[i + 1][(j + digit) % d][0] += dp[i][j][0];
				dp[i + 1][(j + digit) % d][0] %= mod;
			}

			for (int digit = 0; digit < curdig; digit++) {
				//0 -> digit-1 if we want to unrestrict at the next position
				dp[i + 1][(j + digit) % d][0] += dp[i][j][1];
				dp[i + 1][(j + digit) % d][0] %= mod;
			}

			//keep the restriction: add on the digit
			dp[i + 1][(j + curdig) % d][1] += dp[i][j][1];
			dp[i + 1][(j + curdig) % d][1] %= mod;

			// cout << dp[i][j][0] << endl;
		}
	}

	cout << (dp[kl][0][0] + dp[kl][0][1] + mod - 1) % mod << endl;

	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}