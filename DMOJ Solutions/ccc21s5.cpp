#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 15e4 + 5;
int n,m,tree[maxn*2],q[maxn][3];

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a * b / gcd(a,b); }

void update(int l, int r, int val){
	++r;
	for (l += maxn, r += maxn; l < r; l /= 2, r /= 2){
		if (l%2){
			tree[l] = lcm(tree[l],val);
			l++;
		}
		if (r%2){
			--r;
			tree[r] = lcm(tree[r],val);
		}
	}
}

int query(int l, int r){
	// cout << l << " " << r << "\n";
	int res = -1;
	++r;
	for (l += maxn, r += maxn; l < r; l /= 2, r /= 2){
		// cout << res << "\n";
		if (l%2){
			// cout << tree[l] << "\n";
			if (res == -1) res = tree[l];
			else res = gcd(res,tree[l]);
			l++;
		}
		if (r%2){
			--r;
			// cout << tree[r] << "\n";
			if (res == -1) res = tree[r];
			else res = gcd(res, tree[r]);
		}
	}
	return res;
}

int32_t main(){
	cin >> n >> m;
	for (int i = 0; i < 2*maxn; ++i){
		tree[i] = 1;
	}
	for (int i = 0; i < m; ++i){
		int x,y,z; cin >> x >> y >> z;
		q[i][0] = x, q[i][1] = y, q[i][2] = z;
		update(x,y,z);
	}
	for (int i = 1; i < maxn; ++i){
		// cout << tree[i*2] << " " << tree[i*2+1] << "\n";
		tree[i*2] = lcm(tree[i*2],tree[i]);
		tree[i*2+1] = lcm(tree[i*2+1],tree[i]);
		tree[i] = 1;
	}
	for (int i = maxn-1; i > 0; --i){
		tree[i] = gcd(tree[i*2],tree[i*2+1]);
	}
	for (int i = 0; i < m; ++i){
		if (query(q[i][0],q[i][1]) != q[i][2]){
			cout << "Impossible\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i){
		cout << tree[i+maxn] << " ";
	}
	return 0;
}