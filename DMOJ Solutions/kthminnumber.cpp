#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #include <ext/pb_ds/tree_policy.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
#define int 					long long //MLE, TLE, CE
#define f(a) 					for (int i = 0; i < a; ++i)
#define ff(a) 					for (int j = 0; j < a; ++j)
#define f2(a, b) 				for (int i = a; i < b; ++i)
#define ff2(a, b) 				for (int j = a; j < b; ++j)
#define min(a, b) 				((a) < (b) ? (a) : (b))
#define max(a, b) 				((a) > (b) ? (a) : (b))
#define outs(a)					cout << a << " "
#define nl()					cout << "\n"
#define inf 					0x3f3f3f3f
#define llinf 					0x3f3f3f3f3f3f3f3f
#define eb 						emplace_back
#define mem(a, b)				memset(a, b, sizeof a)
#define	dt(a)					decltype(a)
#define fil(a, val) 			fill((RA<dt(a)>::type*)&a,(RA<dt(a)>::type*)((char*)&a+sizeof a),val)
#define SCAN(x) 				while((x=getchar())<'0');char _;for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
int gcd(int a, int b)			{return (b == 0 ? a : gcd(b,a%b));}
int lcm(int a, int b)			{return a * b / (gcd(a,b));}
typedef vector<int> 			vi;
typedef pair<int, int> 			pii;
typedef vector<pair<int,int>> 	vpii;
template<typename T> 			struct RA {typedef T type;};
template<typename T, size_t sz> struct RA<T[sz]> {typedef typename RA<T>::type type;};
template<typename T> void in(T& x){cin>>x;}
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void ui(T& x){SCAN(x);}
template<typename T,typename... Args> void ui(T& x,Args&...args){SCAN(x);ui(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*

*/

struct Node {
	int val = 0;
	Node *l = nullptr, *r = nullptr;
	Node(int x) : val(x), l(nullptr), r(nullptr) {}
	Node(Node *ll, Node *rr) {
		l = ll, r = rr;
		if (l) val += l->val;
		if (r) val += r->val;
	}
};

const int nax = 2e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n,q,arr[nax];
Node* roots[nax];

Node* build(int l = 1, int r = n) {
	if (l == r) return new Node(0);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node* update(Node* node, int pos, int l = 1, int r = n) {
	if (l == r) return new Node(node->val+1ll);
	int mid = (l + r) / 2;
	if (pos > mid) return new Node(node->l, update(node->r, pos, mid + 1, r));
	else return new Node(update(node->l, pos, l, mid), node->r);
}

int find_kth(Node* vl, Node *vr, int tl, int tr, int k) {
	// out(tl,tr);
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->val - vl->l->val;
    if (left_count >= k) return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}

gp_hash_table<int,int> numtoidx;
vi nums;

int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	ui(n,q);
	roots[0] = build();
	int lastans = 0;
	f2(1,n+1){
		ui(arr[i]);
		if (numtoidx.find(arr[i]) == numtoidx.end()){
			numtoidx[arr[i]] = 0;
			nums.eb(arr[i]);
		}
	}
	sort(nums.begin(),nums.end());
	f((long long) nums.size()) numtoidx[nums[i]] = i+1;
	f2(1,n+1) roots[i] = update(roots[i-1], numtoidx[arr[i]]);
	while (q--){
		int l,r,k;
		ui(l,r,k);
		l ^= lastans;
		r ^= lastans;
		k ^= lastans;
		assert(1 <= l and l <= n);
		assert(1 <= r and r <= n);
		assert(l <= r);
		assert(1 <= k and k <= r-l+1);
		out(lastans = nums[find_kth(roots[l-1],roots[r],1,n,k)-1]);
	}
	return 0;
}