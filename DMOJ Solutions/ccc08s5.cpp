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
patrick goes first, then alternating between him and roland
dp[a][b][c][d] stores whether the player that reaches this state wins or loses
n^4 complexity but n <= 30
transition
default to lose at all states at first
at each state check whether there is enough to take away for each reaction
base: if none of these reactions can be triggered then this state is a losing state
if every position it can reach is a winning state, then this state is a losing state (you want to send the other player into a losing state
otherwise it is a winning state

AABDD
ABCD
CCD
BBB
AD
*/

int dp[35][35][35][35];

int solve(int a, int b, int c, int d){
	if (a<0 || b<0 || c<0 || d<0) return 1; //tell the caller that it was winning so that the caller might be losing
	int& cur = dp[a][b][c][d];
	if (cur != -1) return cur;
	if (min(min(min(solve(a-2,b-1,c,d-2),solve(a-1,b-1,c-1,d-1)),
			min(solve(a,b,c-2,d-1),solve(a-1,b,c,d-1))),solve(a,b-3,c,d))){
		return cur = 0;
	}
	return cur = 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	int a,b,c,d;
	while (n--){
		cin >> a >> b >> c >> d;
		mem(dp,-1);
		if (solve(a,b,c,d)) cout << "Patrick" << endl;
		else cout << "Roland" << endl;
	}


	return 0;
}