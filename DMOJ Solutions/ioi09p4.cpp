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
dp[x1][y1][x2][y2] = min cost of cutting the rectangle that has top left corner (x1,y1) and bottom right corner (x2,y2)

base case: x1==x2 and y1==y2 then no cost

transition: simulate every possible horizontal and vertical cut + current piece cost

recursive function with memo

psa to speed up
*/
int raisins[55][55];
int dp[55][55][55][55];

int blocksum(int x1,int y1,int x2,int y2){
	int ret = 0;
	f2(x1,x2+1){
		ff2(y1,y2+1){
			ret += raisins[j][i];
		}
	}
	return ret;
}

int solve(int x1, int y1, int x2, int y2){
	if (x1==x2 && y1==y2){
		return 0;
	}
	int& cur = dp[x1][y1][x2][y2];
	if (cur != -1){
		return cur;
	}
	int ret = inf;
	//vertical cuts
	f(x2-x1){
		ret = min(ret,solve(x1,y1,x1+i,y2)+solve(x1+i+1,y1,x2,y2));
	}
	f(y2-y1){
		ret = min(ret,solve(x1,y1,x2,y1+i)+solve(x1,y1+i+1,x2,y2));
	}
	return cur = ret + blocksum(x1,y1,x2,y2);
}

int n,m;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	f(n){
		ff(m){
			cin >> raisins[i][j];
		}
	}
	mem(dp,-1);
	cout << solve(0,0,m-1,n-1) << endl;

	return 0;
}




















//trailing lines ftw