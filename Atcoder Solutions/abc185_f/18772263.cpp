#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

int n, q;
int arr[300005];
long long tree[1200005];
int a, b;
int inf = INT_MAX;

void build(int v, int l, int r) {
	if (l == r) {
		tree[v] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	tree[v] = (tree[v * 2] ^ tree[v * 2 + 1]);
}

long long query(int v, int l, int r) {
	if (r < a || b < l) {
		return -1;
	}
	elif (a <= l && r <= b) {
		return tree[v];
	}
	int m = (l + r) / 2;
	long long g = query(v * 2, l, m);
	long long h = query(v * 2 + 1, m + 1, r);
	// cout << g << " " << h << "\n";
	if (g == -1) return h;
	if (h == -1) return g;
	return (g ^ h);
}

void update(int v, int l, int r) {
	if (l == r) {
		tree[v] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	if (a <= m) {
		update(v * 2, l, m);
	}
	else {
		update(v * 2 + 1, m + 1, r);
	}
	tree[v] = (tree[v * 2] ^ tree[v * 2 + 1]);
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	cin >> n >> q;
	f(n) {
		cin >> arr[i];
	}
	build(1, 0, n - 1);

	int t;
	f(q) {
		cin >> t;
		cin >> a >> b;
		if (t == 1) {
			a--;
			arr[a] = (arr[a] ^ (b));
			update(1, 0, n - 1);
		}
		else {
			a--;b--;
			cout << query(1, 0, n - 1) << "\n";
		}
	}

	return 0;
}