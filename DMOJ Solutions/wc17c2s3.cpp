#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") //RTE
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define	DT(a)					decltype(a)
#define fil(a, val) 			fill((RA<DT(a)>::type*)&a,(RA<DT(a)>::type*)((char*)&a+sizeof a),val)
template<typename T> 			struct RA {typedef T type;};
template<typename T, size_t sz> struct RA<T[sz]> {typedef typename RA<T>::type type;};
template<typename T> void in(T& x){cin>>x;}
template<typename T,typename... Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){outs(x),out(args...);}
int gcd(int a, int b)			{return (b == 0 ? a : gcd(b,a%b));}
int lcm(int a, int b)			{return a * b / (gcd(a,b));}
typedef vector<int> 			vi;
typedef pair<int, int> 			pii;
typedef vector<pair<int,int>> 	vpii;

////////////////////////////	END OF TEMPLATE	   ////////////////////////////


/*
coord compress
*/

const int nax = 1e6 + 5, mod = 1e9 + 7; const double eps = 1e-9;
int n, allnums[nax], parent[nax], RANK[nax], END[nax], idx = -1;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<int,int,custom_hash> compressed;
pii Q[nax];
bitset<nax> orc;

int Find(int node){
	return parent[node] = (node == parent[node] ? node : Find(parent[node]));
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (RANK[a] < RANK[b]) swap(a, b);
        parent[b] = a;
        END[a] = max(END[a],END[b]);
        if (RANK[a] == RANK[b]) RANK[a]++;
    }
}

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scan(n);
	f(n){
		int op,x,y;
		scan(op);
		if (op == 1){
			scan(x);
			Q[i] = {x,-1};
			if (compressed.find(x) == compressed.end()){
				compressed[x] = 0;
				allnums[++idx] = x;
			}
		}
		else {
			scan(x);scan(y);
			int lo = max(x-y,0), hi = min(x+y,1000000000);
			Q[i] = {lo,hi};
			if (compressed.find(lo) == compressed.end()){
				compressed[lo] = 0;
				allnums[++idx] = lo;
			}
			if (compressed.find(hi) == compressed.end()){
				compressed[hi] = 0;
				allnums[++idx] = hi;
			}
		}
	}
	sort(allnums, allnums+idx+1);
	f(idx+1) compressed[allnums[i]] = i;
	f(nax) parent[i] = i, END[i] = i;
	// parent[idx+1] = END[idx+1] = idx+1;
	int ans = 0;
	f(n){
		if (Q[i].second == -1){
			int pos = compressed[Q[i].first];
			if (END[Find(pos)] == pos){
				orc[pos] = 1;
				++ans;
			}
		}
		else {
			int left = compressed[Q[i].first], right = compressed[Q[i].second];
			int pre = left-1;
			for (int i = left; i <= right; i = END[Find(i)]){
				assert(i != pre);
				if (orc[i]){
					orc[i] = 0;
					--ans;
				}
				Merge(i,i+1);
				pre = i;
			}
		}
		out(ans);
	}
	
	return 0;
}