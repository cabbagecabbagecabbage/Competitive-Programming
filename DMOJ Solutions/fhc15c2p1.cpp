// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #include <ext/pb_ds/tree_policy.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
// #define int 					long long //MLE, TLE, CE
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


const int nax = 1e0 + 5, mod = 1e9 + 7; const double eps = 1e-9;

void solve(){
	//front = bottom, back = front
	deque<int> cur, final, cur2, final2;
	int n; in(n);
	f(n){
		int a; in(a);
		cur.push_back(a);
		cur2.push_back(a);
	}
	final.push_back(cur.front()); cur.pop_front();
	while (!cur.empty()){
		if (cur.front() == final.back()+1){
			final.push_back(cur.front()); cur.pop_front();
		}
		else if (cur.front() == final.front()-1){
			final.push_front(cur.front()); cur.pop_front();
		}
		else if (cur.back() == final.back()+1){
			final.push_back(cur.back()); cur.pop_back();
		}
		else if (cur.back() == final.front()-1){
			final.push_front(cur.back()); cur.pop_back();
		}
		else break;
	}
	if (cur.empty()){
		out("yes");
		return;
	}
	final2.push_back(cur2.back()); cur2.pop_back();
	while (!cur2.empty()){
		if (cur2.front() == final2.back()+1){
			final2.push_back(cur2.front()); cur2.pop_front();
		}
		else if (cur2.front() == final2.front()-1){
			final2.push_front(cur2.front()); cur2.pop_front();
		}
		else if (cur2.back() == final2.back()+1){
			final2.push_back(cur2.back()); cur2.pop_back();
		}
		else if (cur2.back() == final2.front()-1){
			final2.push_front(cur2.back()); cur2.pop_back();
		}
		else break;
	}
	if (cur2.empty()){
		out("yes");
	}
	else out("no");
}



int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; in(t);
	f2(1,t+1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}