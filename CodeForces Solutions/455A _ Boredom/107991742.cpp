#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int nax = 1e5 + 5;
ll freq[nax], n, dp[nax];
ll solve(int x){
 if (x == 0) return 0ll;
 if (x == 1) return freq[1];
 if (dp[x] != -1) return dp[x];
 dp[x] = max(solve(x-1), solve(x-2) + freq[x] * x);
 return dp[x];
}
int main() {
 memset(dp,-1,sizeof(dp));
 cin >> n;
 for (int i = 0; i < n; ++i){
  int a;
  cin >> a;
  freq[a]++;
 }
 cout << (solve(100001)) << "\n";
 return 0;
}