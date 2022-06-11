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
when we reach a state add max val so far to it
then we apply every interval that ends at that index for future
this might seem strange because queries that include the current index are not considered at all; only intervals that ended before the current index was applied. but think about it almost like we're finding the optimal value for now according to our fixed prefix, and eventually when we reach the end we will have to correct answer when there are no intervals that exceed the end

tracing the variables makes it a lot more clear

The reason for processing the interval whose right end is r after the update of dp[r] is that dp[0]-dp[r] are no longer updated by the dp before it. this way we avoid adding multiple times (if we apply then do dp, we might add on the score of one interval twice if we have 2 one's in the range)

it doesnt matter that we dont know that actual final value of an index during the process yet since we didnt apply all the intervals, because the score of every interval affecting it will eventually be added anyways. its varying values only depend on prefix; and since we fixed the prefix, we know that we obtain the maximum value possible. again, the affecting intervals that will be added on afterwards is a constant, so local optimum turns into the best value in the end.

as long as we have a fixed prefix, taking its maximum will eventually give us the right value at the end.

this is very intriguing because while we are using calculated values to build up to the answer, we are also updating all our values at the same time.
*/

const int nax = 200001;

ll tree[4*nax], L[4*nax];
ll ql, qr, qval;
vector<pii> interval[nax];

void update(int v, int l, int r) {
    if (ql <= l && r <= qr){
    	tree[v] += qval;
    	L[v] += qval;
    	return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid) update(v * 2, l, mid);
    if (qr > mid) update(v * 2 + 1, mid + 1, r);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]) + L[v];
}

int n, m;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    in2(n,m);
    ll l,r,v;
    f2(1,m+1){
        in3(l,r,v);
        interval[r].emplace_back(l, v);
    }
    f2(1,n+1){
    	ql = i; qr = i; qval = tree[1];
        update(1, 1, n); //add max val so far to index
        for (pii x : interval[i]){
        	ql = x.first;
        	qr = i;
        	qval = x.second;
        	update(1, 1, n); //apply interval
        }
    }
   	out(max(tree[1], 0ll)); //max of entire range
    return 0;
}















//trailing lines ftw