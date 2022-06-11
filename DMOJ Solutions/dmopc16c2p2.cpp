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

*/

const int nax = 1e5 + 5;
int parent[nax], size[nax], temp[nax];
int n,m,k;

int Find(int node){
	return node == parent[node] ? node : parent[node] = Find(parent[node]);
}

void Merge(int a, int b){
	a = Find(a); b = Find(b);
	if (a != b){
		if (size[a] > size[b]) swap(a,b);
		size[b] += size[a];
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,m);
	f2(1,n+1) parent[i] = i;
	
	f(m){
		in(k);
		ff(k){
			in(temp[j]);
			if (j) Merge(temp[j], temp[j-1]);
		}
	}
	
	vi infected;
	f2(1,n+1) if (Find(1) == Find(i)) infected.eb(i);
	out(infected.size());
	for (int x: infected) cout << x << " "; out("");



	return 0;
}




















//trailing lines ftw