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

/*
i guess this is a thing now

"As an example, suppose we are using p=1000000007. Then, since the minimal polynomial is irreducible over Z/pZ, we know that k(p) must divide p^2−1=1000000014000000048, which factors as 2^4⋅3^2⋅7⋅109^2⋅167⋅500000003. The number of divisors is thus 5⋅3⋅2⋅3⋅2⋅2=360. We can check each one of those by simply combining the powers of the prime divisors and seeing if Q raised to that power is the identity (modp), and we get that the smallest such divisor is k(p)=2000000016. Thus, if we want to compute F2^1024, we need only compute n=2^1024(mod2000000016), and then return Fn."

i absolutely had no idea about this and definitely did not derive this myself (not that i expect anyone to believe i did)

but anyways i guess since we are modulo 1e9+7 we take the n%2000000016
*/

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	unsigned long long n = 0;
	//take input in a weird way
	//note that x << 1 + x << 3 = x*2 + x*8 = x*10 which is like shifting a number up (as we get the chars we addem on)
	char c = getchar();
	while (c >= '0'){
		n = ((n<<1) + (n<<3)) % 2000000016;
		n = (n + (c-'0')) % 2000000016;
		c = getchar();
	}

	Matrix ans;
	ans.m[0][0] = 0;
	ans.m[0][1] = 1;
	ans.m[1][0] = 1;
	ans.m[1][1] = 1;

	ans = mexpo(ans, n);

	cout << ans.m[1][0] << endl;
	return 0;
}