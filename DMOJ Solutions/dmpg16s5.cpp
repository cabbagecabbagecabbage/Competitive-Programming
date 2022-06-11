#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
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
long long prefix[200005];
long long n, k;
set<long long> range;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,k);
	f(n) in(prefix[i]), prefix[i+n] = prefix[i];
	f2(1,2*n) prefix[i] += prefix[i-1];
	ll ans = LLONG_MIN;
	f(n+n){
		//i is ending pos
		if (i > k) range.erase(prefix[i-k-1]);
		range.insert(prefix[i]);
		ans = max(ans, prefix[i] - *range.begin());
	}

	out(ans);
	return 0;
}




















//trailing lines ftw