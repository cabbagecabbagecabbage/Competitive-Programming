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

int n;
char sign[3002];
string s;
int dp[3002][3002];
long long prefix[3002]={};
/*
state:
dp[i][j] stores the number of permutations using the first i numbers with respect to the first i-1 signs, and j is the last number in the permutation (we only care about the last number when deciding the next number to add to the permutation)

transition:
say we have the sample
_<_>_<_
and we already have the state
1<2>_
now we want to fill in one more number with respect to the sign
the sign is >. now we do the following trick: pick any number (greater than 0) less than or equal to j which in this case is 2. then we have 1<2>2, which is false for now. to force this to become true, we add 1 to every number in the previous permutation that is greater or equal to the number we pick. now the sequence becomes 1<3>2, a valid sequence.
another number we can pick is 1. 1<2>1, which is true but 1 is used twice. to force validity, we add 1 to each of the rest of the permutation where the number is greater than 1: 2<3>1, another valid permutation. since each number we pick is difference and the number that we add 1 to are different, theres no way we double count permutations. and by picking every possible number to add to the end, we are exhausting every permutation possible.

so now continuing with the example, take the state
2<3>1<_
the number we pick now has to be strictly bigger than the last number j which is 1 (and smaller than i where i is the current state; recall dp[i][j] stores state of first i numbers). we can pick any number, say 2. similarly a valid sequence can be forced: 2<3>1<2 -> 3<4>1<2 (by adding 1 to the numbers that are greater than 2). notice we can't pick 1 because then we would have 3<4>2<1 where (2<1) doesnt work: you're not satisfying the current inequality. (by the way, this is just for proof purposes, theres no need to do this during the implementation)
*/


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> s;
	int idx = 2;
	for (char c:s){
		sign[idx] = c;
		idx++;
	}
	dp[1][1] = 1; //first number is 1 - the only permutation with the first 1 number
	// f2(2,n+2) prefix[1][i] = 1;
	int lb, ub; //lowerbound, upperbound, inclusive. notice that the logic is reversed when backtracking
	int mod = 1e9+7;
	f2(2,n+1){
		ff2(2,i+2){
			prefix[j] = prefix[j-1]+dp[i-1][j-1];
			prefix[j] %= mod;
		}
		ff2(1,i+1){
			if (sign[i]=='<'){
				lb = 1;
				ub = j-1;
			}
			else {
				lb = j;
				ub = i;
			}
			// for (int k=lb; k<=ub; k++){
			// 	// cout << "i-1: " << i-1 << "\tk: " << k << endl;
			// 	dp[i][j] += dp[i-1][k];
			// 	dp[i][j] %= mod;
			// }
			dp[i][j] = prefix[ub+1]-prefix[lb]+mod;
			dp[i][j] %= mod;
			// cout << dp[i][j] << endl;
		}
	}

    int ans = 0;
    f2(1,n+1){
    	ans += dp[n][i];
    	ans %= mod;
    }
    cout << ans << endl;
 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}