#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
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

/*
root the tree
at each subtree, try to concatenate the 2 tallest children to form the diameter. count the diameter by multiplying the number of ways to form one height * number of ways to form the other height
return the maximum depth of the subtree and the number of ways the maximum depth cna be achieved
*/
#define int long long
const int nax = 4e5 + 5;

int dia, cnt;
int n;
vi adj[nax];


pii solve(int node, int prev){
	int nh = 0, nc = 1, h, c;
	for (int x: adj[node]){
		if (x == prev) continue;
		tie(h,c) = solve(x,node);
		h+=1;
		int join = nh + h;
		//update answer
		if (join > dia) dia = join, cnt = c * nc;
		elif (join == dia) cnt += c * nc;

		//update node
		if (h > nh) nh = h, nc = c;
		elif (h == nh) nc += c;

	}
	return {nh,nc};
}
	
int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n); int a,b;
	f(n-1){
		in2(a,b);
		adj[a].eb(b);
		adj[b].eb(a);
	}
	solve(1,0);
	out2(dia+1,cnt);	
	return 0;
}




















//trailing lines ftw