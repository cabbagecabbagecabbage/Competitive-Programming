#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 10007;

struct Matrix {
	vector<vector<int>> m;
	int h,w;
	Matrix(int hh, int ww){
		h = hh; w = ww;
		m.resize(h,vector<int>(w,0));
	}
	Matrix operator *(const Matrix& other){
		// cout << w << " " << other.h << "\n";
		assert(w == other.h);
		Matrix product(h,other.w);
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < other.w; ++j){
				for (int k = 0; k < w; ++k){
					product.m[i][j] += m[i][k] * other.m[k][j];
				}
				product.m[i][j] %= mod;
			}
		}
		return product;
	}
};

Matrix mpow(Matrix base, int power){
	Matrix product(base.h,base.w);
	for (int i = 0; i < product.h; ++i)	product.m[i][i] = 1;
	while (power){
		if (power % 2){
			product = product * base;
		}
		base = base * base;
		power /= 2;
	}
	return product;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int d,n; cin >> d >> n;
	Matrix init(d,1);
	for (int i = 0; i < d; ++i) cin >> init.m[i][0];
	Matrix trans(d,d);
	for (int i = 0; i < d-1; ++i) trans.m[i][i+1] = 1;
	for (int i = 0; i < d; ++i) cin >> trans.m[d-1][d-1-i];
	Matrix ans = mpow(trans,n) * init;
	cout << (ans.m[0][0] + mod) % mod << "\n";
	return 0;
}