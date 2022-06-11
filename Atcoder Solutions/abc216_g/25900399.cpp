#include <bits/stdc++.h>
using namespace std;

/*

*/

const int nax = 2e5 + 5;
int n,m;

struct Q{
	int r,l,x;
} q[nax];
int t[nax*2];

void update(int pos, int val){
	for (t[pos += nax] = val; pos /= 2;){
		t[pos] = t[pos * 2] + t[pos * 2 + 1];
	}
}

int query(int l, int r){
	int a = 0;
	for (l += nax, r += nax; l < r; l /= 2, r /= 2){
		if (l % 2) a += t[l++];
		if (r % 2) a += t[--r];
	}
	return a;
}

int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int l,r,x;
		cin >> l >> r >> x;
		q[i] = {r,l,x};
	}
	sort(q,q+m, [](Q a, Q b){
		return a.r < b.r;
	});
	stack<int> zeroes;
	int curidx = 1;
	for (int i = 0; i < m; ++i){
		// cout << q[i].l << " " << q[i].r << " " << q[i].x << "\n";
		// cout << curidx << "\n";
		while (curidx <= q[i].r){
			zeroes.push(curidx++);
		}
		// cout << curidx << "\n";
		while (query(q[i].l,q[i].r+1) < q[i].x){
			assert(!zeroes.empty());
			update(zeroes.top(), 1); zeroes.pop();
		}
	}
	for (int i = 0; i < n; ++i){
		cout << t[nax+i+1] << " ";
	}
	cout << "\n";
	
	return 0;
}