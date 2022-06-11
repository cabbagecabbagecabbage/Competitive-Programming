#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*
find lcs between string and reverse
*/
int pre[5005];
int cur[5005];
string s;
int n;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> s;
	string rs(s);
	reverse(rs.begin(),rs.end());
	f2(1,n+1){
		ff2(1,n+1){
			cur[j] = max(pre[j],cur[j-1]);
			if (s[i-1]==rs[j-1]) cur[j] = pre[j-1] + 1;
		}
		ff2(1,n+1) pre[j] = cur[j];
	}
	cout << n - cur[n] << endl;

	return 0;
}