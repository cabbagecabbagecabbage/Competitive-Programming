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

int n,k;
struct Matrix {
	vector<vector<int>> m;
	Matrix(){
		m.resize(n,vector<int> (n));
	}
	Matrix operator *(const Matrix& other) {
		Matrix product;
		f(n) ff(n) for (int k = 0; k < n; k++) {
			product.m[i][k] += (m[i][j] * other.m[j][k]);
		}
		return product;
	}
};

Matrix mexpo(Matrix m, int k) {
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
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	
	cin >> n >> k;

	Matrix graph;

	f(n){
		ff(n){
			cin >> graph.m[i][j];
		}
	}

	graph = mexpo(graph,k);

	int ans = 0;
	f(n){
		ff(n){
			ans += graph.m[i][j];
		}
	}

	cout << ans << endl;
	return 0;
}