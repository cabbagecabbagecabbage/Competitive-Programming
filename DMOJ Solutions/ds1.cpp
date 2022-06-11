#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (unsigned long long i = 0; i < a; i++)
#define ff(a) for (unsigned long long j = 0; j < a; j++)
#define f2(a, b) for (unsigned long long i = a; i < b; i++)
#define ff2(a, b) for (unsigned long long j = a; j < b; j++)
#define fb(a) for (unsigned long long i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

unsigned long long freq[100005] = {};
unsigned long long tree[100005] = {};
unsigned long long arr[100005] = {};

void update(unsigned long long a[], unsigned long long i, unsigned long long v){
	while (i <= 100005){
		a[i] += v;
		i += (i & -i);
	}
}

unsigned long long query(unsigned long long a[], unsigned long long i){
	unsigned long long sum = 0;
	while (i > 0){
		sum += a[i];
		i -= (i & -i);
	}
	return sum;	
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long val;
	f(n){
		cin >> val;
		arr[i] = val;
		update(tree,i+1,val);
		update(freq,val,1);
	}
	char op;
	unsigned long long idx, qv;
	f(m){
		cin >> op;
		if (op == 'C'){
			cin >> idx >> qv;
			update(tree,idx,qv-arr[idx-1]);
			idx--;
			update(freq,arr[idx],-1);
			arr[idx] = qv;
			update(freq,qv,1);
		}
		elif (op == 'S'){
			unsigned long long ql,qr;
			cin >> ql >> qr;
			cout << query(tree,qr) - query(tree,ql-1) << endl;
		}
		else{
			cin >> qv;
			cout << query(freq,qv) << endl;
		}
	}

	return 0;
}




















//trailing lines ftw