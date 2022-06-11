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
typedef pair<int,int> pii;

const long long mod = 1e9;
long long a, b, n;

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
	Matrix product(2, 2);
	f(2) product.m[i][i] = 1;
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
	cin >> a >> b >> n;
	if (n==0) {
		cout << a << endl;
		return 0;
	}
	Matrix fib(2,2);
	fib.m = {{0,1},{1,1}};

	fib = mexpo(fib,n-1);

	Matrix init(1,2);
	init.m = {{a},{b}};

	fib = fib * init;

	cout << fib.m[1][0] << endl;

	return 0;
}