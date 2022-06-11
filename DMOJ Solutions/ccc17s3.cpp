#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
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
the idea is to use frequency lists

1. a frequency list for all the wood lengths
2. a frequency list for all the board lengths

iterate over all pairs (by wood lengths) and add their sum to board lengths

pairing a wood length with itself results in ((number of woods with that length) // 2) boards of twice that length
pairing a wood length with another wood length results in (min(number of wood of length 1, number of wood length 2))

then we take the maximum frequency of the board lengths
*/

int n,l;
int wood[2005], board[4005];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	in(n);
	f(n){
		in(l);
		wood[l]++;
	}
	
	f(2001){
		if (wood[i]){
			ff(i+1){
				if (wood[j]){
					if (i==j) board[i+j] += wood[i] / 2;
					else board[i+j] += min(wood[i],wood[j]);
				}
			}
		}
	}
	
	int ans = 0;
	int number = 0;
	f(4001){
		if (board[i]==ans) number++;
		if (board[i]>ans){
			number = 1;
			ans = board[i];
		}
	}
	cout << ans << " " << number << endl;
	return 0;
}




















//trailing lines ftw