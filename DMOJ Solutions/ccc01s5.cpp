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
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*

*/
int m,n;
vector<int> ans;
string a[40],b[40];

bool solve(int seqsize, string first, string second){
	if (first == second && seqsize > 0) return true;
	if (seqsize == m-1) return false;
	f(n){
		if (solve(seqsize+1,first+a[i],second+b[i])){
			ans.pb(i+1);
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(m,n);
	f(n) in(a[i]);
	f(n) in(b[i]);

	
	if (solve(0,"","")){
		out(ans.size());
		for (int x = ans.size()-1; x > -1; x--) out(ans[x]);
	}
	else out("No solution.");



	return 0;
}




















//trailing lines ftw