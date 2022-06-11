#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
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
struct SegmentTreeLazyBottomUp {
	struct C {
		// Indices are 0-indexed and ranges are inclusive
		using Data = int;
		using Lazy = int;
		// Returns the query default value of type Data
		static Data qdef() { return 0; }
		// Returns the lazy default value of type Lazy
		static Lazy ldef() { return 0; }
		// Returns value of Data l merged with Data r
		static Data merge(const Data &l, const Data &r) { return l + r; }
		// Returns Lazy r applied to Data L
		static Data applyLazy(const Data &l, const Lazy &r) { return r + l; }
		// Returns Lazy v when applied over a segment of length k
		static Lazy getSegmentVal(const Lazy &v, int k) { return v * k; }
		// Returns value of Lazy l merged with Lazy r
		static Lazy mergeLazy(const Lazy &l, const Lazy &r) { return l + r; }
	};
	using Data = typename C::Data; using Lazy = typename C::Lazy;
	int N, lgN; vector<Data> TR; vector<Lazy> LZ;
	void apply(int i, const Lazy &v, int k) {
		TR[i] = C::applyLazy(TR[i], C::getSegmentVal(v, k)); if (i < N) LZ[i] = C::mergeLazy(LZ[i], v);
	}
	void eval(int i, int k) {
		TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
		if (LZ[i] != C::ldef()) TR[i] = C::applyLazy(TR[i], C::getSegmentVal(LZ[i], k));
	}
	void propagate(int i) {
		int h = lgN + 1, k = 1 << lgN, ii = i >> h;
		for (; h > 0; ii = i >> --h, k /= 2) if (LZ[ii] != C::ldef()) {
		  apply(ii * 2, LZ[ii], k); apply(ii * 2 + 1, LZ[ii], k); LZ[ii] = C::ldef();
		}
	}
	SegmentTreeLazyBottomUp(int N):
	N(N), lgN(N == 0 ? 0 : __lg(N)), TR(N * 2, C::qdef()), LZ(N, C::ldef()) {
    	// generate(TR.begin() + N, TR.end(), f); //fill leaves with existing array if desired
		for (int i = N - 1; i > 0; i--) TR[i] = C::merge(TR[i * 2], TR[i * 2 + 1]);
	}
	void update(int l, int r, const Lazy &v) {
		propagate(l += N); propagate(r += N); bool bl = 0, br = 0; int k = 1;
		for (; l <= r; l /= 2, r /= 2, k *= 2) {
			if (bl) eval(l - 1, k); 
			if (br) eval(r + 1, k);
			if (l % 2) { apply(l++, v, k); bl = 1; } 
			if (!(r % 2)) { apply(r--, v, k); br = 1; }
		}
		for (l--, r++; r; l /= 2, r /= 2, k *= 2) {
			if (bl) eval(l, k); 
			if (br && (!bl || l != r)) eval(r, k);
		}
	}
	Data query(int l, int r) {
		propagate(l += N); propagate(r += N); Data ql = C::qdef(), qr = C::qdef();
		for (; l <= r; l /= 2, r /= 2) {
			if (l % 2) ql = C::merge(ql, TR[l++]); 
			if (!(r % 2)) qr = C::merge(TR[r--], qr);
		}
		return C::merge(ql, qr);
	}
	Data query(int pos) {
		int l = pos, r = pos;
		propagate(l += N); propagate(r += N); Data ql = C::qdef(), qr = C::qdef();
		for (; l <= r; l /= 2, r /= 2) {
			if (l % 2) ql = C::merge(ql, TR[l++]); 
			if (!(r % 2)) qr = C::merge(TR[r--], qr);
		}
		return C::merge(ql, qr);
	}
};


const int nax = 1e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n;
pii masts[nax];
int sails_at_height[nax];

SegmentTreeLazyBottomUp tree(nax);

int bs1(int lo, int hi, int val){
	//finding left bound of level
	int ans = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (tree.query(mid) == val){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return ans;
}

int bs2(int lo, int hi, int val){
	//finding right bound of level
	int ans = -1;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (tree.query(mid) == val){
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	return ans;
}
	

int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	ui(n);
	f(n) ui(masts[i].first, masts[i].second);
	sort(masts, masts+n);
	
	f(n){
		int height = masts[i].first, sails = masts[i].second;
		int point = height - sails + 1;
		int left = bs1(1,point,tree.query(point)), right = bs2(point,height,tree.query(point));
		assert(left != -1 and right != -1);
		// out("a",left,right);
		if (right+1 <= height) tree.update(right+1, height, 1);
		// out("b",right+1,height);
		if (left <= left + right - point) tree.update(left, left + right - point, 1);
		// out("c",left,left + right - point);
	}
	// assert(0);
	int ans = 0;
	for (int h = 1; tree.query(h) != 0; ++h){
		int sails = tree.query(h);
		ans += sails * (sails - 1) / 2;
	}
	out(ans);
	
	
	return 0;
}