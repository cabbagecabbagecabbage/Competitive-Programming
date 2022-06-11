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

const int mod = 1e9;
long long binpow(long long num, long long power){
	long long ret = 1;
	while (power){
		if (power%2){
			ret = (ret * num) % mod;
		}
		num = (num * num) % mod;
		power /= 2;
	}
	return ret;
}
string s;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n = 100;
	cin >> s;
	if (s.length() < 3) n = stoi(s);
	long long ans = 0;
	f(n){
		ans = (ans + binpow(10,i/2)) % mod;	
	}
	ans = (ans * 9) % mod;
	cout << ans << endl;

	return 0;
}