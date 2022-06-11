#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
oops had a typo and wasted 2 hours yay

dp[i] min cost to get to stone 1
dp[1] = 0
dp[i] = h_i^2 + C + min{ -2h_i*h_j + h_j^2+dp[j], 1 <= j < i }

maintain deque of lines sorted by decreasing slope (front has biggest slope, back has smallest slope). we will access the min from the front

smaller slope will always overtake bigger slope as we go, the question is when (depends on constant)

if for some x value the front is no longer the min (compare with the one after it), then we pop it since it will no longer be useful. repeat until the front gives the min.

update dp with min

before we insert into back, pop out the back if its itnersection with current line is to the left of intersection between the back and the one before it.
*/

struct line {
	int m,b,idx;
	int eval(int x){ return m*x+b; }
	double intersectionX(line other){ return (double) (b-other.b ) / (other.m-m); }
};

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,c; cin >> n >> c;
	vector<int> dp(n+1),h(n+1);
	for (int i = 1; i <= n; ++i) cin >> h[i];
	dp[1] = 0;
	deque<line> cht;
	cht.push_back((line) {-2*h[1],h[1]*h[1]+dp[1],1});
	// for (int i = 0; i < cht.size(); ++i)
			// cout << cht[i].m << " " << cht[i].b << " " << cht[i].idx << "\n";
	// cout << dp[1] << "\n";
	for (int i = 2; i <= n; ++i){
		int x = h[i];
		while (cht.size() > 1 and cht[1].eval(x) < cht[0].eval(x)) cht.pop_front();
		dp[i] = cht[0].eval(x) + x*x + c;
		line curline = (line) {-2*x,x*x+dp[i],i};
		// for (int j = 0; j < cht.size(); ++j)
			// cout << cht[j].m << " " << cht[j].b << " " << cht[j].idx << "\n";
		while (cht.size() > 1 and curline.intersectionX(cht.back()) < cht.back().intersectionX(cht[cht.size()-2])) cht.pop_back();
		cht.push_back(curline);
		
		// cout << dp[i] << "\n";
	}
	cout << dp[n] << "\n";
	return 0;
}