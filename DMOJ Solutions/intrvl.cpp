#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpii;
typedef tuple<int,int,int> tiii;


gp_hash_table<int, int> table;
const int nax = 1e5 + 5;
int n,q,a,b,x;
pii updates[nax*2];
int nums[nax], query[nax];
bool c(pii a, pii b){ return a.first < b.first;}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,q);
	for (int i = 0; i < 2*n; i += 2) {
		in2(a,b);
		updates[i].first = a; updates[i].second = 1;
		updates[i+1].first = b+1; updates[i+1].second = -1;
	}
	sort(updates,updates+2*n,c);
	f(q) in(x),	query[i] = nums[i] = x;
	sort(nums,nums+q);
	int freq = 0, ptr = 0, pre = 0;
	for (int i = 0; i < 2*n; ++i){
		if (i < 2*n-1 && updates[i+1].first == updates[i].first){
			updates[i+1].second += updates[i].second;
			continue;
		}
		else{
			pre = freq;
			freq += updates[i].second;
		}
		while (ptr < q && nums[ptr] < updates[i].first)	table[nums[ptr++]] = pre;
	}
	f(q) out(table[query[i]]);

	return 0;
}




















//trailing lines ftw