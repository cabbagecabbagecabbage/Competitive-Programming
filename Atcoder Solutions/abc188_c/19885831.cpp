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
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;

/*

*/

ll arr[(1 << 16) + 5];
int n;
int a;

pair<ll,ll> solve(int l, int r){
	if (l == r) return {arr[l],l};
	int m = (l + r) / 2;
	pair<ll,ll> a = solve(l,m), b = solve(m+1,r);
	if (a.first > b.first) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f((1 << n)) in(arr[i]);
	int m = (0 + (1 << n) - 1) / 2;
	pair<ll,ll> a = solve(0,m), b = solve(m+1,(1 << n)-1);
	if (a.first < b.first) out(a.second+1);
	else out(b.second+1);
	return 0;
}




















//trailing lines ftw