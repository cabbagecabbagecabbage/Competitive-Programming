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
https://www.youtube.com/watch?v=7hFWrKa6yRM
*/

struct box{
	int s, w, val;
	box(){}
	box(int s2, int w2, int val2){
		s = s2;
		w = w2;
		val = val2;
	}
};
box boxes[1005];

int n;
const int maxm = 20001; // w + s
long long dp[maxm]; //dp[i] = maximum value using i weight

bool compare(box first, box second){
	return (first.w + first.s) < (second.w + second.s);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	int w,s,v;
	f(n){
		in3(w,s,v);
		boxes[i] = box(s,w,v);
	}
	sort(boxes,boxes + n,compare);

	f(n){
		int weight = boxes[i].w;
		int value = boxes[i].val;
		int strength = boxes[i].s;
		for (int j = 20000; j >= weight; j--){
			if (weight + strength >= j) dp[j] = max(dp[j], dp[j-weight] + value);
		}
	}
	long long ans = 0;
	f2(1,20001){
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;

	return 0;
}




















//trailing lines ftw