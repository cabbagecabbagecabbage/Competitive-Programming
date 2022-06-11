#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
typedef vector<int> vi;

long long arr[402];
long long memo[402][402];
long long prefix[405];

long long solve(int l, int r){
	if (l==r) return arr[l];
	if (memo[l][r] != -1) return memo[l][r];
	long long res = LLONG_MAX;
	f2(l,r) res = min(res,prefix[r+1]-prefix[l]+solve(l,i)+solve(i+1,r));
	memo[l][r] = res;
	return res;
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    int n;
    cin >> n;
    f(n) cin >> arr[i];
    f2(1,n+1) prefix[i] = arr[i-1]+prefix[i-1];
    memset(memo,-1,sizeof(memo));
    cout << solve(0,n-1)-prefix[n];n()

	return 0;
}