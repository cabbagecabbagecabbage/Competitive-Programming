#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0;j<a;j++)
#define fff(a) for (int k=0; k<a; l++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fff2(a,b) for (int k=a; k<b; k++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define sint(a) scanf("%d",&a);
#define sints(a,b) scanf("%d%d",&a,&b);
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define print(a) printf("%d\n", a);
#define n() printf("\n");

int ninf = INT_MIN;
int inf = INT_MAX;

#define maxn 50006
// K must satisfy K>=log2(maxn)
#define K 18
int arr[maxn];
int big[maxn][K + 1];
int small[maxn][K + 1];
int logs[maxn+1];

int n, q;
int ql,qr;

void computelogs(){
	logs[1] = 0;
	f2(2,maxn+1){
		logs[i] = logs[i/2]+1;
	}
}

void maketable(){
	f(n) {
		small[i][0] = big[i][0] = arr[i];
	}
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			small[i][j] = min(small[i][j - 1], small[i + (1 << (j - 1))][j - 1]);
			big[i][j] = max(big[i][j - 1], big[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int computemin(){
	// zero indexed
	int j = logs[qr-ql+1];
	return min(small[ql][j], small[qr - (1 << j) + 1][j]);
}

int computemax(){
	// zero indexed
	int j = logs[qr-ql+1];
	return max(big[ql][j], big[qr - (1 << j) + 1][j]);
}

int main() {
	sints(n,q)
	f(n){
		sint(arr[i])
	}
	computelogs();
	maketable();
	f(q){
		sints(ql,qr)
		ql--;qr--;
		print(computemax()-computemin())
	}
	return 0;
}