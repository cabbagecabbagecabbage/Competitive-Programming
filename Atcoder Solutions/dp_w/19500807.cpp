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
when we reach a state set it to the max val so far
then we apply every interval that ends at that index for future
this might seem strange because queries that include the current index are not considered at all; only intervals that ended before the current index was applied.
but in the future every interval would be applied and we will take the maximum

*/

const int nax = 200001;

ll s[4*nax], t[4*nax];
ll ql, qr, qval;
vector<pii> intervals[nax];

void update(int x, int l, int r) {
    if (ql <= l && r <= qr){
    	s[x] += qval;
    	t[x] += qval;
    	return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid) update(x * 2, l, mid);
    if (qr > mid) update(x * 2 + 1, mid + 1, r);
    s[x] = max(s[x * 2], s[x * 2 + 1]) + t[x];
}

int n, m;
int main() {
    in2(n,m);
    ll l,r,v;
    f2(1,m+1){
        in3(l,r,v);
        intervals[r].emplace_back(l, v);
    }
    f2(1,n+1){
    	ql = i; qr = i; qval = s[1];
        update(1, 1, n); //set arr[i] to the max val so far
        for (pii x : intervals[i]){
        	ql = x.first;
        	qr = i;
        	qval = x.second;
        	update(1, 1, n); //apply interval
        }
    }
   	out(max(s[1], 0ll));
    return 0;
}















//trailing lines ftw