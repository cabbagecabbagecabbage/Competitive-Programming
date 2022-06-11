#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
typedef vector<int> vi;

int n,k;
int dp[100002]; 
//dp[i] stores whether the person who reaches this state wins or loses
vi nums;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    int m,maxel=0;
	cin >> n >> k;
	f(n){
		cin >> m;
		nums.push_back(m);
		dp[m] = 1; //reach here, take away m and u win.
		maxel = max(maxel,m);
	}

	f(k+1){
		if (dp[i]==0){
			for (int x: nums){
				if (i-x>=0){
					if (dp[i-x]==0){
						dp[i] = 1;
						break;
					}	
				}
			}
		}
	}
	if (dp[k]) cout << "First";
	else cout << "Second";
	n()

	return 0;
}