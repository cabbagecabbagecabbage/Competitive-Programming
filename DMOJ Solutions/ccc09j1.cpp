#include <bits/stdc++.h>
using namespace std;

signed main(){
    int ans = 91;
    int a,b,c; cin >> a >> b >> c;
    cout << "The 1-3-sum is " << ans + a + c + b * 3 << "\n";
    return 0;
}