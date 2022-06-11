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

const int nax = 1030;

int S;
int arr[nax][nax];


void update(int x, int y, int add) {
	//note that x is the row, y is the column
	int y1;
	while (x <= S) {
		y1 = y;
		while (y1 <= S) {
			arr[x][y1] += add;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

ll sum(int x, int y) {
	//rect sum from arr[1][1] to arr[x][y]
	ll res = 0;
	while (x > 0) {
		int y1 = y;
		while (y1 > 0) {
			res += arr[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return res;
}

int main() {
	
	int l, b, r, t;
	int op, x, y, inc;
	while (1) {
		in(op);
		if (op == 3) break;
		if (op == 0){
			in(S);
			continue;
		}
		elif (op == 1) {
			in3(x,y,inc);
			x++;y++;
			update(y,x,inc);
		}
		elif (op == 2) {
			in2(l,b);
			in2(r,t);
			l++;b++;r++;t++;
			out(sum(t,r)-sum(t,l-1)-sum(b-1,r)+sum(b-1,l-1));
		}
	}
}









//trailing lines ftw