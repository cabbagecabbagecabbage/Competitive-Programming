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

*/


const int nax = 1e5 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int row[nax], col[nax];
tuple<int,int,int,int> edges[nax*2];

int rowFind(int node){
	return row[node] = (row[node] == node ? node : rowFind(row[node]));
}

void rowMerge(int a, int b){
	a = rowFind(a), b = rowFind(b);
	row[a] = b;
}

int colFind(int node){
	return col[node] = (col[node] == node ? node : colFind(col[node]));
}

void colMerge(int a, int b){
	a = colFind(a), b = colFind(b);
	col[a] = b;
}

int32_t main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m,p,q;
	ui(n,m,p,q);
	int idx = 0, sum = 0;
	f(p){
		int a,b,c;
		ui(a,b,c);
		sum += c*(n);
		edges[idx++] = {c,0,a,b};
	}
	f(q){
		int a,b,c;
		ui(a,b,c);
		sum += c*(m);
		edges[idx++] = {c,1,a,b};
	}
	sort(edges, edges + idx);
	int mergedrow = n-1, mergedcol = m-1;
	int cost = 0;
	idx = 0;
	f(n+1) row[i] = i;
	f(m+1) col[i] = i;
	while (mergedrow or mergedcol){
		int c,isrow,a,b;
		tie(c,isrow,a,b) = edges[idx++];
		// out(c,isrow,a,b);
		if (isrow){
			if (rowFind(a) != rowFind(b)){
				rowMerge(a,b);
				cost += c*(mergedcol+1);
				mergedrow--;
			}
		}
		else {
			if (colFind(a) != colFind(b)){
				colMerge(a,b);
				cost += c*(mergedrow+1);
				mergedcol--;
			}
		}
	}
	// out(sum,cost);
	out(sum - cost);	
	return 0;
}