#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<int,long long,custom_hash> dp;

long long solve(int num){
	// out(num);
	if (dp[num]) return dp[num];
	int weights = 2;
	 //num of subtrees
	for (int start = num, end = num / weights; start >= 2;){
		dp[num] += (start - end) * solve(weights-1);
		weights = num / start+1;
		start = end;
		end = num / weights;
	}
	return dp[num];
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	dp[1] = 1;
	dp[2] = 1;
	int n; cin >> n;
	cout << solve(n) << "\n";
	return 0;
}