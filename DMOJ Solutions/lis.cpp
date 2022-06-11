#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

int n, num;
int inf = INT_MAX;
int piles[1000001];

int binarysearch(int s, int num){
	//returns the index of the leftmost pile with top card less than num
	int high = s-1, low = 0, mid, index;
	while (1){
		mid = (high + low) / 2;
		// cout << "mid: " << mid << "\n";
		if (piles[mid] >= num && (mid == 0 || piles[mid-1] < num)){
			//leftmost pile found
			index = mid;
			break;
		}
		elif (high==low){
			index = -1;
			break;
		}
		elif (piles[mid] < num){
			//jump forward
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	// cout << "result: " << index << "\n";
	return index;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	piles[0] = inf;
	cin >> n;
	int s = 1;
	f(n){
		cin >> num;
		int res = binarysearch(s,num);
		if (res == -1){
			piles[s] = num;
			s++;
		}
		else{
			piles[res] = num;
		}
		// f(n) cout << piles[i] << " ";
		// cout << "\n";
	}
	// f(n) cout << piles[i] << " ";
	// cout << "\n";
	cout << s << "\n";
	return 0;
}