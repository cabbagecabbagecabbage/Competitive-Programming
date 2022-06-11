#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
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

*/
const int nax = 15e4+5;
int memo[nax][3], n, order[3], dif[3][nax];

int solve(int index, int contestant){
	if (index == n) return contestant == 2 ? 0 : inf;
	int& cur = memo[index][contestant];
	if (cur != -1) return cur;
	cur = solve(index+1, contestant) + dif[order[contestant]][index];
	if (contestant < 2){
		cur = min(cur,solve(index+1, contestant+1) + dif[order[contestant]][index]);
	}
	return cur;
}

int help(int a, int b, int c){
	mem(memo,-1);
	order[0] = a;
	order[1] = b;
	order[2] = c;
	return solve(0,0);
}
	

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f(3){
		ff(n){
			in(dif[i][j]);
		}
	}
	int ans = inf;
	ans = min(ans,help(0,1,2));
	ans = min(ans,help(0,2,1));
	ans = min(ans,help(1,0,2));
	ans = min(ans,help(1,2,0));
	ans = min(ans,help(2,1,0));
	ans = min(ans,help(2,0,1));
	out(ans);

	return 0;
}




















//trailing lines ftw