#include <bits/stdc++.h>
using namespace std;
#define f2(a,b) for (int i=a; i<b; i++)
#define f(a) for (int i=0; i<a; i++)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define schar(a) scanf(" %c",&a);
#define print(a) printf("%d\n", a);

int ninf = INT_MIN;
int inf = INT_MAX;

int n, q;
int op, ql, qr, a;
int inc;
long long tree1[4000005][2] = {};
long long tree2[4000005][2] = {};

int sumrange(int a, int b) {
	//gauss formula; [a,b] inclusive
	return (a + b) * (b - a + 1) / 2;
}

void pushdown(int v, int l, int r, int m) {
	tree1[v * 2][1] += (1 - ql) * (m - l + 1) * a;
	tree1[v * 2 + 1][1] += (1 - ql) * (r - (m + 1) + 1) * a;

	tree2[v * 2][1] += a;
	tree2[v * 2 + 1][1] += a;
}

void pushup(int v) {
	tree1[v][0] = tree1[v * 2][0] + tree1[v * 2 + 1][0];
	tree2[v][0] = tree2[v * 2][0] + tree2[v * 2 + 1][0];
}

void update(int v, int l, int r) {
	if (r < ql || qr < l) {
		return;
	}
	int m = (l + r) / 2;
	if (ql <= l && r <= qr) {
		//propagate children
		if (l!=r){
			pushdown(v, l, r, m);
		}
		//update current segment
		tree1[v][0] += (1 - ql) * a * (r - l + 1); //(1-ql)*a for each index, (qr-ql+1) indices
		tree2[v][0] += sumrange(l, r) * a; //factoring out the a, we are left with the sum of the indices in the range
	}
	else {
		//apply previous
		tree1[v][0] += tree1[v][1];
		tree2[v][0] += tree2[v][1] * sumrange(l, r);
		tree1[v][1] = 0;
		tree2[v][1] = 0;

		//recur down
		update(v * 2, l, m);
		update(v * 2 + 1, m + 1, r);
		pushup(v);
	}
}

int sum1(int v, int l, int r) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return tree1[v][0];
	}
	else {
		int m = (l + r) / 2;
		return sum1(v * 2, l, m) + sum1(v * 2 + 1, m + 1, r);
	}
}

int sum2(int v, int l, int r) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return tree2[v][0];
	}
	else {
		int m = (l + r) / 2;
		return sum2(v * 2, l, m) + sum2(v * 2 + 1, m + 1, r);
	}
}

int main() {
	sints(n, q)

	f(q) {
		sint(op);
		if (op == 1) {
			sints(ql, qr)
			sint(a)
			update(1, 1, n);
		}
		else {
			sints(ql, qr)
			print(sum1(1, 1, n) + sum2(1, 1, n))
		}
	}

	return 0;
}