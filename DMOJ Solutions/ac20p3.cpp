#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (long long i = 0; i < a; i++)
#define ff(a) for (long long j = 0; j < a; j++)
#define f2(a, b) for (long long i = a; i < b; i++)
#define ff2(a, b) for (long long j = a; j < b; j++)
#define fb(a) for (long long i = a - 1; i >= 0; i--)
#define ll long long
/*

*/

const int nax = 5e5 + 5;

char s[nax], t[nax];
int ss[nax], tt[nax];
int a,b;
set<int> occ[26];
int ex[26];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in2(a,b);
	in(s);
	in(t);
	f(a){
		ss[i] = s[i] - 'a';
	}
	f(b){
		tt[i] = t[i] - 'a';
	}
	f(a){
		occ[ss[i]].insert(i);
		ex[ss[i]] = 1;
	}
	f(b){
		if (ex[tt[i]] == 0){
			out(-1);
			return 0;
		}
	}
	
	ll ti = 0;
	ll si = 0;
	ll loops = 0;
	while (ti < b){
		//found
		auto nex = occ[tt[ti]].lower_bound(si);
		if (nex != occ[tt[ti]].end()){
			si = *nex + 1;			
			ti++;	
		}
			
		//not found
		else{
			si = 0;
			loops++;
		}
	}
	out(loops*a + si);
	return 0;
}




















//trailing lines ftw