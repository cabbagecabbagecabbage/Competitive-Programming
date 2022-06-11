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
sum of digits is S
dp[i][free][sum] stores the number of numbers whose length is i, whether it is free from constraints, and the sum of their digits

2 different numbers can only reuse common subproblems if the state of the subproblem is free, otherwise we would be applying conditions according to one number but irrelevant to the other
instead of return cur = res;
we do if (free) return cur = res; else return res;
*/

long long dp[20][2][150];
int S;
string s;
long long solve(int idx, int free, int sum){
	if (idx==0) return sum == S;
	if (sum > S) return 0;
	long long& cur = dp[idx][free][sum];
	if (free && cur != -1) return cur;
	long long res = 0;
	if (free){
		f(10){
			res += solve(idx-1, 1, sum+i);
		}
		return cur = res;
	}
	else{
		int curdig = s[idx-1]-'0';
		f(curdig){
			res += solve(idx-1, 1, sum+i);
		}
		res += solve(idx-1, 0, sum + curdig);
		return res;
	}
}

long long actuallysolve(long long input){
	s = to_string(input);
	reverse(s.begin(),s.end());
	return solve(s.length(),0,0);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	mem(dp,-1);
	long long a,b;
	cin >> a >> b >> S;

	cout << actuallysolve(b) - actuallysolve(a-1) << endl;
	
	long long low = a;
	long long high = b;
	long long mid, ans;
	while (high > low){
		mid = (high + low) / 2;
		if (actuallysolve(mid)>actuallysolve(a-1)){
			high = mid;
			ans = mid;
			continue;
		}
		low = mid+1;
	}
	cout << ans << endl;
	return 0;
}




















//trailing lines ftw