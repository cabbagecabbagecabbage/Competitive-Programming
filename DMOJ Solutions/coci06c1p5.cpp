//not my solution, zhouxizhang2004's solution. i like it better than recursive so im taking it.
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
#define p(a) cout << a << "\n";

typedef vector<int> vi;
double p[20][20];
double dp[1 << 20];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f(n){
        ff(n) cin >> p[i][j],p[i][j] /= 100;
    }

    dp[0] = 1;
    f(1<<n){
        int b = __builtin_popcount(i);
        
        ff(n){
            if (i & (1 << j)) dp[i] = max(dp[i],dp[i ^ (1 << j)] * p[j][b-1]);
        }
    }
    cout << fixed;
    cout << setprecision(12);
    cout << dp[(1 << n) - 1] * 100;n()

    return 0;
}