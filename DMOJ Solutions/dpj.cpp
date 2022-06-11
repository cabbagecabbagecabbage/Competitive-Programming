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
typedef pair<int,int> pii;

int n;
double memo[302][302][302];

double solve(int a, int b, int c){
	if (a+b+c <= 0) return 0;
	if (memo[a][b][c] > 0) return memo[a][b][c];
	int s = a+b+c;

	//now we only consider the probability out of the probability that it is full
	double ret = (double) n;
	if (a>0) ret += a*solve(a-1,b,c);//take a plate with 1 sushi, it becomes a plate of 0 sushi
	if (b>0) ret += b*solve(a+1,b-1,c);//take a plate with 2 sushis, it becomes a plate of 1 sushi
	if (c>0) ret += c*solve(a,b+1,c-1);//take a plate with 3 sushis, it becomes a plate of 2 sushi
	return memo[a][b][c] = (double) ret/s;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int count[4]={};
	f(n){
		int plate;
		cin >> plate;
		count[plate]++;
	}
	memset(memo,-1,sizeof(memo));
	cout << fixed;
	cout << setprecision(16);
	cout << solve(count[1],count[2],count[3]);n()
    
	return 0;
}