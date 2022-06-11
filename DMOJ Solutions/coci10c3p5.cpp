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
sum of all max elements of each subarray - sum of all min elements of each subarray

predict how many times an element is the desired element of a subarray
max elements:
	find the first elements greater than current element on left and right side
	call those indices l and r
	must contain this element, so we choose an index not to the right and one not to the left of cur element
	ans += arr[i] * (i - (l+1) + 1) * ((r-1) - i + 1)
	
same logic with min elements
	
*/


const int nax = 3e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n, arr[nax], r[nax], R[nax], l[nax], L[nax];
stack<int> s;

int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	ui(n);
	f(n) ui(arr[i]);
	//l[i]
	f(n){
		while (!s.empty() and arr[i] < arr[s.top()]) s.pop();
		l[i] = (s.empty() ? -1 : s.top());
		s.push(i);
	}
	while (!s.empty()) s.pop();
	//L[i]
	f(n){
		while (!s.empty() and arr[i] > arr[s.top()]) s.pop();
		L[i] = (s.empty() ? -1 : s.top());
		s.push(i);
	}
	while (!s.empty()) s.pop();
	//r[i]
	for (int i = n-1; i >= 0; --i){
		while (!s.empty() and arr[i] <= arr[s.top()]) s.pop();
		r[i] = (s.empty() ? n : s.top());
		s.push(i);
	}
	while (!s.empty()) s.pop();
	//R[i]
	for (int i = n-1; i >= 0; --i){
		while (!s.empty() and arr[i] >= arr[s.top()]) s.pop();
		R[i] = (s.empty() ? n : s.top());
		s.push(i);
	}
	int ans = 0;
	f(n){
		ans += arr[i] * (i - L[i]) * (R[i] - i);
		ans -= arr[i] * (i - l[i]) * (r[i] - i);
	}
	out(ans);
	return 0;
}