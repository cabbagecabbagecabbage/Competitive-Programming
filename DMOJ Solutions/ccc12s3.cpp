#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << b << endl
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
int freq[1001];
int n, maxfreq;
int maxnum = -inf, minnum = inf;
int minsecond = inf, maxsecond = -inf, secondfreq;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	int num;
	f(n){
		in(num);
		freq[num]++;
		maxfreq = max(maxfreq,freq[num]);
	}
	f(1001){
		if (freq[i] == maxfreq){
			maxnum = max(maxnum,i);
			minnum = min(minnum,i);
			freq[i] = -1;
		}
	}
	if (maxnum > minnum){
		out(maxnum - minnum);
		return 0;
	}
	maxfreq = 0;
	f(1001){
		maxfreq = max(maxfreq,freq[i]);
	}
	f(1001){
		if (freq[i] == maxfreq){
			minsecond = min(minsecond,i);
			maxsecond = max(maxsecond,i);
		}
	}
	out(max(abs(maxnum - minsecond),abs(maxnum - maxsecond)));
	

	return 0;
}




















//trailing lines ftw