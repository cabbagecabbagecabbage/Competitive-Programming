#include <bits/stdc++.h>
using namespace std;
#define f2(a,b) for (int i=a; i<b; i++)
#define f(a) for (int i=0; i<a; i++)
#define elif else if

int ninf = INT_MIN;

struct data {
	long long sum, pref, suff, ans;  //sum of entire segment, max prefix, max suffix, sum maximum
};

data combine(data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}

int n, q;
int ql, qr;
char op;
data tree[400005];
int arr[100005];


data make_data(int val) {
	data res;
	res.sum = res.pref = res.suff = res.ans = val;
	return res;
}

data invalid = make_data(ninf);

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = make_data(arr[l]);
	} else {
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
	}
}

void update(int v, int l, int r) {
	if (l == r) {
		tree[v] = make_data(arr[l]);
	} else {
		int m = (l + r) / 2;
		if (ql <= m)
			update(v * 2, l, m);
		else
			update(v * 2 + 1, m + 1, r);
		tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
	}
}

data query(int v, int l, int r) {
	//no overlap (not in range)
	if (l > qr || r < ql) {
		return invalid;
	}
	//overlap
	if (ql <= l && qr >= r) {
		return tree[v];
	}
	//partial overlap
	else {
		int m = (l + r) / 2;
		data a = query(v * 2, l, m);
		data b = query(v * 2 + 1, m + 1, r);
		if (a.ans == invalid.ans) return b;
		if (b.ans == invalid.ans) return a;
		return combine(a, b);
	}
}


int main() {
	scanf("%d%d", &n, &q);
	f(n) {
		scanf("%d", &arr[i]);
	}
	build(1, 0, n - 1);
	f(q) {
		scanf(" %c %d %d", &op, &ql, &qr);
		if (op == 'S') {
			ql--; //position from 1 index to 0 index
			arr[ql] = qr;
			update(1, 0, n - 1); //ql -> pos, qr -> val
		}
		elif (op == 'Q') {
			ql--;
			qr--;
			printf("%lld\n", query(1, 0, n - 1).ans);
		}
	}
}