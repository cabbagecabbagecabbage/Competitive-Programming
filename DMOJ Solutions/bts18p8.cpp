#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define elif else if

//preocompute f(k) for k in [K,K+5000]
//bulid tree with bitset length 5000 storing whether i+k is in the range

//then use segtree to answer maximum query:
//if node is in range, go backwards to test if the value is 1 and if f(i+k) != -1, (then it will be biggest value)

//updating the tree:
//update children according to lazy while recurring down
//if node is in range, update node, increase lazy for children

long long N, Q, K;
long long arr[100005];
int f[5001] = {}; //index i stores f(K+i)
vector<long long> check;
bitset<5001> tree[400005];
int lazy[400005] = {};
long long op, ql, qr, val;

void computeprime() {
	//[K,K+5000]
	//first find primes up to sqrt of K, then just sieve the range
	long long rootk = sqrt(K + 5000) + 1;
	int notprime[rootk] = {};
	notprime[2] = 0;
	for (long long i = 3; i < rootk; i+=2) {
		if (notprime[i] == 0) {
			for (long long j = 2; i * j < rootk; j++) {
				notprime[i * j] = 1;
			}
		}
	}

	for (long long i = 2; i < rootk; i++) {
		if (notprime[i] == 0) {
			for (long long j = max((i * i), (K + i - 1) / i * i); j <= K + 5000; j += i) {
				f[j - K] = -1;
			}
		}
	}
	for (int i=5000; i>-1; i--){
		if (f[i]==0){
			check.push_back(i);
		}
	}
}

void build(int v, int l, int r) {
	if (l == r) {
		tree[v][arr[l] - K] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	tree[v] = (tree[v * 2] | tree[v * 2 + 1]);
}

void shift(int v, int s) {
	if (s > 0) {
		tree[v] <<= s;
	}
	elif (s < 0) {
		tree[v] >>= -1 * s;
	}
}

void pushdown(int v, int l, int r) {
	shift(v * 2, lazy[v]);
	shift(v * 2 + 1, lazy[v]);
	lazy[v * 2] += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

long long query(int v, int l, int r) {
	if (l > qr || r < ql) {
		return -1;
	}
	elif (ql <= l && r <= qr) {
		//find largest
		for (int i: check) {
			if (tree[v][i] == 1) {
				return i + K;
			}
		}
		return -1;
	}
	int m = (l + r) / 2;
	pushdown(v, l, r);
	return max(query(v * 2, l, m), query(v * 2 + 1, m + 1, r));
}

void update(int v, int l, int r) {
	if (l > qr || r < ql) {
		return;
	}
	elif (ql <= l && r <= qr) {
		lazy[v] += val;
		shift(v, val);
		return;
	}
	int m = (l + r) / 2;
	pushdown(v, l, r);
	update(v * 2, l, m);
	update(v * 2 + 1, m + 1, r);
	tree[v] = (tree[v * 2] | tree[v * 2 + 1]);
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	cin >> N >> Q >> K;
	computeprime();
	f(N) {
		cin >> arr[i];
	}
	build(1, 0, N - 1);
	f(Q) {
		cin >> op;
		if (op == 1) {
			cin >> ql >> qr;
			ql--;
			qr--;
			cout << query(1, 0, N - 1) << "\n";
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