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

/*
to quote the competitive programmer's handbook
"The powers of an adjacency matrix of a graph have an interesting property. When V is an adjacency matrix of an unweighted graph, the matrix V^n contains the numbers of paths of n edges between the nodes in the graph."

some of the template code is from errichto
*/
const int mod = 1e9 + 7;

int n;
long long K;

struct Matrix {
	vector<vector<long long>> m;
	Matrix() {
		m.resize(n, vector<long long>(n));
	}
	Matrix operator *(const Matrix& other) {
		Matrix product;
		f(n) ff(n) for (int k = 0; k < n; k++) {
			product.m[i][k] += (m[i][j] * other.m[j][k]) % mod;
			product.m[i][k] %= mod;
		}
		return product;
	}
};

Matrix mexpo(Matrix m, long long k) {
	Matrix product;
	f(n) product.m[i][i] = 1;
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> K;
	Matrix graph;
	f(n){
		ff(n){
			cin >> graph.m[i][j];
		}
	}

	graph = mexpo(graph,K);
	long long ans = 0;
	f(n){
		ff(n){
			ans += graph.m[i][j] % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}