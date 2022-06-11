#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define elif else if
#define endl "\n"
typedef vector<int> vi;
typedef pair<int,int> pii;

char size;
int num;
int jersey[1000005];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int j,a;
	cin >> j >> a;
	f2(1,j+1){
		cin >> size;
		if (size=='M') jersey[i] = 2;
		if (size=='L') jersey[i] = 3;
		if (size=='S') jersey[i] = 1;
	}
	int ans = 0;
	f(a){
		int si;
		cin >> size >> num;
		if (size=='M') si = 2;
		if (size=='L') si = 3;
		if (size=='S') si = 1;
		if (jersey[num] >= si){
			ans++;
			jersey[num] = 0;
		}
	}
	cout << ans << endl;
    

 	// cout << fixed;
	// cout << setprecision(2);
	return 0;
}