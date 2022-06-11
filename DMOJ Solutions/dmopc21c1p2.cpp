// Problem: P1 - Partial Game
// Contest: DMOJ - DMOPC '21 Contest 1
// URL: https://dmoj.ca/problem/dmopc21c1p1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// #pragma GCC optimize("Ofast")
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
keep sorted array
build from bottom up in the second stack
while not done:
	let the element previously sorted be p
	find the next element that goes on top of what we have sorted and call it q
	move everything above p to the first stack
	move q and everything above it on top of p

*/


const int nax = 1e0 + 5, mod = 1e9 + 7; const double eps = 1e-9;

vpii sorted, stack1, stack2;
vi ans;
int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int id = 0;
	int n; in(n);
	f(n){
		int a; in(a);
		stack1.eb(a,++id);
		sorted.eb(a,id);
	}
	reverse(stack1.begin(),stack1.end());
	pii p;
	sort(sorted.begin(),sorted.end());
	for (int j = n-1; j >= 0; --j){
		//move to stack1
		if (j != n-1){
			bool start = false; int r = 0;
			f((int)stack2.size()){
				if (start) stack1.eb(stack2[i]);
				if (!start and stack2[i] == sorted[j+1]){
					start = true;
					r = stack2.size() - 1 - i;
				}
			}
			if (r) ans.eb(-r);
			while (r--) stack2.pop_back();
		}
		//move to stack 2
		bool start = false; int r = 0;
		f((int)stack1.size()){
			if (!start and stack1[i] == sorted[j]){
				start = true;
				r = stack1.size() - i;
				// out(r,i,stack1[0].first,stack1[0].second,sorted[);
			}
			if (start) stack2.eb(stack1[i]);
		}
		// out(sorted[j].first, r);
		if (r) ans.eb(r);
		while (r--) stack1.pop_back();
		// outs("stack1"); f((int)stack1.size()) outs(stack1[i].first); nl();
		// outs("stack2"); f((int)stack2.size()) outs(stack2[i].first); nl();
	}
	out(ans.size()+1);
	for (int i: ans) out(i);
	out(-n);
	return 0;
}