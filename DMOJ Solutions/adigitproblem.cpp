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
dp[i][free][mask]
i digits
mask represents the subset of numbers required that still needs to be satisfied  0 <= ai <= 9
only return 1 when everything is satisfied

leading 0's ??
*/

const int mod = 1e9 + 7;

string s;
long long dp[1005][2][2][1030];

void add(long long &a, long long b){
	a += b;
	if (a >= mod) a -= mod;
}

long long solve(int idx, int start, int free, int mask){
	if (idx == (int) s.length()){
		return mask==0; //only return 1 if the condition is satisfied
	}
	long long& cur = dp[idx][start][free][mask];
	if (cur != -1) return cur;
	
	long long res = 0;
	if (free){
		//use all digits
		if (start) add(res,solve(idx+1,1,1,mask&(~(1))));
		else add(res,solve(idx+1,0,1,mask));
		f2(1,10){
			add(res, solve(idx+1,1,1,mask&(~(1<<i))));
		}
	}
	else{
		int curdig = s[idx]-'0';
		f(curdig){
			if (i==0){
				if (start) add(res,solve(idx+1,1,1,mask&(~(1))));
				else add(res,solve(idx+1,0,1,mask));
			}
			else add(res, solve(idx+1,1,1,mask&(~(1<<i))));
		}
		if (curdig==0){
				if (start) add(res,solve(idx+1,1,0,mask&(~(1))));
				else add(res,solve(idx+1,0,0,mask));
		}
		else add(res,solve(idx+1,1,0,mask&(~(1<<curdig))));
	}
	return cur = res;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, digit;
	cin >> n;
	int mask = 0;
	f(n){
		cin >> digit;
		mask |= (1 << digit);
	}
	mem(dp,-1);
	cin >> s;
	long long ans = 0;
	
	if (n==1 && digit==0) ans++;
	add(ans,solve(0,0,0,mask));
	cout << ans << endl;
	return 0;
}




















//trailing lines ftw