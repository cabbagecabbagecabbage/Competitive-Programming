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
summary of statement: minimize the number of test cases such that ppl who ac will still ac and ppl who wa will still wa. theres needs to be at least 1 test case

ppl who aced will still ac no matter what we remove

keep an array where each index stores the bitmask that represents the subset of people the test case (at that index) will fail

n <= 20 while m <= 50 so we need to bitmask on n (number of ppl) and long long with m

dp[mask] stores the minimum subset of test cases needed to fail the subset of people represented by mask
transition is we try to add each test case to the current subset of test cases and see if its worth (also if the future is 0 then we force it)

answer is subset in dp[(1<<n)-1];
*/

bitset<64> dp[1100000];
long long fail[53];
long long n,m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string cases;
	f(n){
		int failed = 0;
		cin >> cases;	
		ff(m){
			if (cases[j]=='X'){
				fail[j] |= (1<<i); //add person i to the subset who fails the case
				failed = 1;
			}
		}
		if (!failed){
			ff(m) fail[j] |= (1<<i);
		}
	}
	for (int mask = 0; mask < (1<<n); mask++){
		for (int testcase = 0; testcase < m; testcase++){
			long long currenttestamt = dp[mask].count(); //current number of testcases
			long long next = mask|fail[testcase]; //subset of people who will fail if we add this testcase
			long long nexttestamt = dp[next].count(); //number of testcases in the next state
			if (fail[testcase]){
				//if a non 0 amount of people fail this
				if (nexttestamt==0 || currenttestamt + 1 < nexttestamt){
					//if adding this test cases is better or if the next state is 0 we force it
					if (mask==0 || currenttestamt){
						//if we are at base case or the current number of test cases is non 0
						dp[next] = dp[mask];dp[next][testcase] = 1;
					}
				}
			}
		}
	}
	bitset<64>& ans = dp[(1<<n)-1];
	cout << ans.count() << endl;
	f(64){
		if (ans[i]) cout << i+1 << " ";
	}
	cout << endl;

  return 0;
}