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

const long long mod = 1e9 + 7;
long long n, k, t, c;

struct Matrix {
	vector<vector<long long>> m;
	long long wid;
	long long hei;
	Matrix(long long width, long long height) {
		wid = width;
		hei = height;
		m.resize(height, vector<long long>(width, 0));
	}
	Matrix operator *(const Matrix& other) {
		Matrix product(other.wid, hei);
		f(hei) ff(wid) for (long long k = 0; k < other.wid; k++) {
			// cout << i << " " << j << " " << k << endl;
			product.m[i][k] += (m[i][j] * other.m[j][k]) % mod;
			product.m[i][k] %= mod;
		}
		return product;
	}
};

Matrix mexpo(Matrix m, long long p) {
	Matrix product(t + 1, t + 1);
	f(t + 1) product.m[i][i] = 1;
	while (p > 0) {
		if (p % 2) {
			product = product * m;
		}
		m = m * m;
		p /= 2;
	}
	return product;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> t >> c;

	Matrix a(t + 1, t + 1);
	f(t) {
		a.m[i+1][i] = 1;
	}
	a.m[0][t] = k;
	a.m[t][t] = 1;

	a = mexpo(a, n - 1);

	Matrix C(1, t + 1);
	C.m[t][0] = c;

	a = a * C;
	long long ans = 0;
	f(t + 1) {
		ans = (ans+a.m[i][0]) % mod;
	}
	ans = (ans+a.m[t][0]) % mod;

	cout << ans << endl;

	return 0;
}