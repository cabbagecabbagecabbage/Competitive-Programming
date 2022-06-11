#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;

const long long mod = 1e9 + 13;

long long binpow(long long m, long long p) {
	long long product = 1;
	while (p > 0) {
		if (p % 2) {
			product = (product * m) % mod;
		}
		m = (m * m) % mod;
		p /= 2;
	}
	return product;
}

int main() {
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	long long first = binpow(2, n - 2);

	long long second = binpow(2, n / 2 - 1);

	switch (n % 8) {
	case 2:
		second = 0;
		break;
	case 6:
		second = 0;
		break;
	case 5:
		second = -1 * second;
		break;
	case 3:
		second = -1 * second;
		break;
	case 4:
		second = -1 * second;
		break;
	}

	long long ans = (first + second + mod) % mod;

	cout << ans << endl;
	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}