#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (long long i=0; i<a; i++)
#define ff(a) for (long long j=0; j<a; j++)
#define f2(a,b) for (long long i=a; i<b; i++)
#define ff2(a,b) for (long long j=a; j<b; j++)
#define fb(a) for (long long i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<long long> vi;
typedef pair<long long, long long> pii;


/*
we calculate the number of paths we cannot take, then subtract that from the total.
number of ways to go from (a,b) to (c,d) (assuming that it is possible) is (c-a+d-b) choose (c-a). the proof is we need c-a R instructions and d-b D instructions. something like RRRDRRDD would be one path, and we want the total number of distinct permutations of that.

since we need to do everything in mod 1e9+7, we use mod inverses instead of division.
by fermats little theorem we know a^(n-1) = 1 mod n where n is prime
dividing both sides by a we have a^(n-2) = 1/a mod n
we use binary exponentiation to calculate a^(n-2)

see details in implementation
*/
long long n, h, w;
pii points[3005];
long long factorial[200005], inverse[200005];
const long long mod = 1e9 + 7;

long long binpow(long long num, long long pow) {
	long long ret = 1;
	while (pow) {
		if (pow % 2) ret = (ret * num) % mod;
		num = (num * num) % mod;
		pow /= 2;
	}
	return ret;
}

void precompute() {
	factorial[0] = 1;
	inverse[0] = 1;
	f2(1, 200001) {
		factorial[i] = (factorial[i - 1] * i) % mod;
		inverse[i] = binpow(factorial[i], mod - 2);
	}
}

long long nck(long long n, long long k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return (long long) ((factorial[n] * inverse[k]) % mod * inverse[n - k]) % mod;
}

bool compare(pii a, pii b) {return (a.first + a.second) < (b.first + b.second);}


long long dp[3005]; //dp[i] stores the number of paths that goes from start to i without going to another wall first


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> h >> w >> n;
	long long r, c;
	f(n) {
		cin >> r >> c;
		points[i] = make_pair(r, c);
	}
	sort(points, points + n, compare);

	precompute();

	points[n] = make_pair(h, w);

	f(n + 1) {
		//for every wall (from closest to furthest)
		long long total = nck(points[i].first - 1 + points[i].second - 1, points[i].second - 1);
		ff(i) {
			//for every wall that can be reached before the current wall
			long long ydiff = points[i].first - points[j].first;
			long long xdiff = points[i].second - points[j].second;
			total -= (dp[j] * nck(xdiff + ydiff, xdiff)) % mod;
			if (total < 0) total += mod;
		}
		dp[i] = total;
		// cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}