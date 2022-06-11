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

const int mod = 1e9 + 7;

struct Matrix {
	unsigned long long m[2][2] = {{0, 0}, {0, 0}};
	Matrix operator *(const Matrix& other) {
		Matrix product;
		f(2) ff(2) for (int k = 0; k < 2; k++) {
			product.m[i][k] += (m[i][j] * other.m[j][k]) % mod;
			product.m[i][k] %= mod;
		}
		return product;
	}
};

Matrix mexpo(Matrix m, unsigned long long k) {
	Matrix product;
	f(2) product.m[i][i] = 1;
	while (k > 0) {
		if (k % 2) {
			product = product * m;
		}
		m = m * m;
		k /= 2;
	}
	return product;
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	unsigned long long n;
	cin >> n;

	Matrix ans;
	ans.m[0][0] = 0;
	ans.m[0][1] = 1;
	ans.m[1][0] = 1;
	ans.m[1][1] = 1;

	ans = mexpo(ans, n);

	cout << ans.m[1][0] << endl;
	return 0;
}