#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << "\n"
#define out2(a, b) cout << a << " " << b << "\n"
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

/*

*/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const int nax = 1e5 + 5;
int n,q,i,j,op;
int c[nax],r[nax];
gp_hash_table<int, gp_hash_table<int,int>> table;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(n,q);
	while (q--){
		in3(op,i,j);
		if (op == 1){
			c[i]++;
			r[j]++;
			table[i][j]++;
		}
		else{
			out((c[i]+r[j]-table[i][j])%2);
		}
	}


	return 0;
}