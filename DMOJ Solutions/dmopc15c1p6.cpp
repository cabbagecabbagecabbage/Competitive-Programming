#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define fff(a) for (int k=0; k<a; l++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fff2(a,b) for (int k=a; k<b; k++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

long long M, N, Q;
long long tree[800005];
long long lazy[800005] = {};
int arr[200005];
long long op, ql, qr, val;

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = arr[l]%M;
		// print2(l,r)
		// print(tree[v])
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % M;
	// print2(l,r)
	// print(tree[v])
}

void pushdown(int v, int l, int r) {
	int m = (l + r) / 2;
	tree[v * 2] += lazy[v] * (m - l + 1);
	tree[v * 2] %= M;
	tree[v * 2 + 1] += lazy[v] * (r - (m + 1) + 1);
	tree[v * 2 + 1] %= M;
	lazy[v * 2] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

long long query(int v, int l, int r) {
	if (l > qr || r < ql) {
		return 0;
	}
	elif (ql <= l && r <= qr) {
		return tree[v];
	}
	int m = (l + r) / 2;
	pushdown(v, l, r);
	return (query(v * 2, l, m) + query(v * 2 + 1, m + 1, r)) % M;
}

void update(int v, int l, int r) {
	if (l > qr || r < ql) {
		return;
	}
	elif (ql <= l && r <= qr) {
		lazy[v] += val;
		tree[v] += val * (r - l + 1);
		tree[v] %= M;
		return;
	}
	int m = (l + r) / 2;
	pushdown(v, l, r);
	update(v * 2, l, m);
	update(v * 2 + 1, m + 1, r);
	tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % M;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> Q;
	f(N) {
		cin >> arr[i];
	}
	build(1, 0, N - 1);
	f(Q) {
		cin >> op;
		if (op == 2) {
			cin >> ql >> qr;
			ql--;
			qr--;
			cout << query(1, 0, N - 1) % M << "\n";
		}
		else {
			cin >> ql >> qr >> val;
			ql--;
			qr--;
			update(1, 0, N - 1);
		}
	}
	return 0;
}