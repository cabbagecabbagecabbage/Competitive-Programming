#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> void in(T& x){cin>>x;}
template<typename T,typename...Args> void in(T& x,Args&...args){cin>>x,in(args...);}
template<typename T> void out(const T& x){cout<<x<<"\n";}
template<typename T,typename... Args> void out(const T& x,const Args&...args){cout<<x<<" ",out(args...);}
#define f(a) for (int i = 0; i < a; ++i)
#define ff(a) for (int j = 0; j < a; ++j)
#define f2(a, b) for (int i = a; i < b; ++i)
#define ff2(a, b) for (int j = a; j < b; ++j)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/*
 
*/
#define int long long
const int nax = 1e5 + 5;
 
int freq[nax], n, dp[nax];
 
int solve(int x){
 if (x == 0) return 0;
 if (x == 1) return freq[1];
 if (dp[x] != -1) return dp[x];
 return dp[x] = max(solve(x-1), solve(x-2) + freq[x] * x);
}
 
 
int32_t main() {
 ios_base::sync_with_stdio(false); cin.tie(0);
 mem(dp,-1);
 in(n);
 f(n){
  int a;
  in(a);
  freq[a]++;
 }
 out(solve(100001));
 return 0;
}