#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
https://codeforces.com/blog/entry/11080

keep tree at the parent of each set


*/

using namespace __gnu_pbds;
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ost;
#define fbo find_by_order
const int nax = 1e5+5;
int parent[nax], ssize[nax], srank[nax];
ost order_stat_tree[nax];
int n,m,q,a,b,x,y,k;


int sfind(int node){
	if (parent[node] == node) return node;
	return parent[node] = sfind(parent[node]);
}


void smerge(int a, int b){
	int para = sfind(a), parb = sfind(b);
	if (para == parb) return;
	f(ssize[para]){
		order_stat_tree[parb].insert(*order_stat_tree[para].fbo(0));
		order_stat_tree[para].erase(order_stat_tree[para].fbo(0));
	}
	parent[para] = parb;
	ssize[parb] += ssize[para];
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f2(1,n+1){
		in(k);
		parent[i] = i;
		ssize[i] = 1;
		srank[k] = i; //srank[i] stores student index whose rank is i
		order_stat_tree[i].insert(k);
	}
	f(m){
		in2(a,b);
		smerge(a,b);
	}
	in(q); char op;

	f(q){
		in(op);
		if (op == 'B'){
			in2(x,y);
			smerge(x,y);
		}
		elif (op == 'Q'){
			in2(x,k);
			int parentx = sfind(x);
			int ans = srank[*order_stat_tree[parentx].fbo(k-1)]; 
			out((ans < 1 ? -1 : ans));
			//student index of the kth ranking student in the set containing x
		}
	}
	return 0;
}




















//trailing lines ftw