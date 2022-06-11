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
we solve for (0,b) - (0,a)
we construct the numbers one by one
we need to make sure the digit we add is not the same as the last 2 digits
dp[i][free][a][b] stores the number of non-palindromes with i digits, whether it is free to use all digits, and the last 2 digits a and b (let a be the last one, and b the one before a)

*/

long long dp[20][2][15][15];
string s;

long long solve(int idx, int free, int a, int b){
	if (idx==(int)s.length()) return 1;
	long long& cur = dp[idx][free][a][b];
	if (cur != -1) return cur;
	long long ans = 0;
	if (free){
		//can use all digits
		f(10){
			if (i != a && i != b) ans += solve(idx+1, 1, i, a);
		}
	}
	else{
		long long curdig = s[idx] - '0';
		f(curdig){
			if (i != a && i != b){
				ans += solve(idx+1, 1, i, a);
			}
		}
		if (curdig != a && curdig != b) ans += solve(idx+1, 0, curdig, a);
	}
	return cur = ans;
}

long long actuallysolve(long long input){
	if (input < 0) return 0;
	if (input < 10) return input+1;
	mem(dp,-1);
	s = to_string(input);
	int first = s[0]-'0';
	long long ans = 1;
	f2(1,first+1){
		ans += solve(1,i!=first,i,i);
	}
	f2(2,(int)s.length()+1){
		ff2(1,10){
			ans += solve(i,1,j,j);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long a,b;
	cin >> a >> b;
	long long ans = actuallysolve(b)-actuallysolve(a-1);
	cout << ans << endl;
	return 0;
}




















//trailing lines ftw