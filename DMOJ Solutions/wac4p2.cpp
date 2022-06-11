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
int ans=INT_MAX;
int voters[5002]; //weight
int points[5002]; //value
long long minweight[5002];//stores min voters needed to achieve i points
//NOT FINISHED. TO BE FIXED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    int psum = 0;
    f(n){
    	int v,p;
    	cin >> v >> p;
    	voters[i] = v/2 + 1;
    	points[i] = p;
    	psum += p;
    }
    psum++;
    f(psum) minweight[i] = 0x3f3f3f3f3f3f3f3f;
    minweight[0] = 0;
    ff(n){//j
    	fb(psum){//i
    		if (i-points[j]>-1) minweight[i] = min(minweight[i-points[j]]+voters[j],minweight[i]);
            else break;
    	}
    }

    //go from psum to psum/2+1 inclusive and find the min of voters
    long long ans = LLONG_MAX;
    f2((psum-1)/2+1,psum) ans = min(ans,minweight[i]);//,cout << minweight[i] << " ";

    cout << ans << "\n";

	return 0;
}