/*
https://dmoj.ca/problem/utso15p3/editorial
*/
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
#define ull unsigned long long

int ninf = INT_MIN;
int inf = INT_MAX;

int n,m;
int mod=1000000007;

int case2memo[100005]={0};

int case2(int n){
	if (n<1){
		return 0;
	}
	elif (n==1){
		return 1;
	}
	if (case2memo[n-1]==0) case2memo[n-1] = case2(n-1);
	if (case2memo[n-3]==0) case2memo[n-3] = case2(n-3);
	return (case2memo[n-1]+case2memo[n-3])%mod;
}


ull A[100005];
ull B[100005];
ull C1[100005];
ull C2[100005];
ull D[100005];

ull b(int n);
ull c1(int n);
ull c2(int n);
ull d(int n);

ull a(int n){
	if (n<1){
		return 0;
	}
	if (n==1){
		return 1;
	}
	if (A[n]!=-1){
		return A[n];
	}
	// if (A[n-1]==-1) A[n-1] = a(n-1);
	// if (B[n-2]==-1) B[n-2] = b(n-2);
	// if (C1[n-3]==-1) C1[n-3] = c1(n-3);
	// return ((A[n-1]+B[n-2])%mod+C1[n-3])%mod;
	A[n] = (a(n-1)+b(n-2)+c1(n-3))%mod;
	return A[n];
}

ull b(int n){
	if (n<1){
		return 0;
	}
	if (B[n]!=-1){
		return B[n];
	}
	// if (A[n-2]==-1) A[n-2] = a(n-2);
	// if (C2[n-3]==-1) C2[n-3] = c2(n-3);
	// if (D[n-1]==-1) D[n-1] = d(n-1);
	// if (D[n-3]==-1) D[n-3] = d(n-3);
	// return ((A[n-2]+C2[n-3])%mod+(D[n-1]+D[n-3])%mod)%mod;
	B[n] = (a(n-2)+c2(n-3)+d(n-1)+d(n-3))%mod;
	return B[n];
}

ull c1(int n){
	if (n<1){
		return 0;
	}
	if (C1[n]!=-1){
		return C1[n];
	}
	// if (A[n-2]==-1) A[n-2] = a(n-2);
	// if (C2[n]==-1) C2[n] = c2(n);
	// return (A[n-2]+C2[n])%mod;
	C1[n] = (a(n-2)+c2(n))%mod;
	return C1[n];
}


ull c2(int n){
	if (n<1){
		return 0;
	}
	if (C2[n]!=-1){
		return C2[n];
	}
	// if (A[n-1]==-1) A[n-1] = a(n-1);
	// if (A[n-2]==-1) A[n-2] = a(n-2);
	// if (C2[n-3]==-1) C2[n-3] = c2(n-3);
	// if (D[n-1]==-1) D[n-1] = d(n-1);
	// if (D[n-3]==-1) D[n-3] = d(n-3);
	// return ((A[n-1]+A[n-2])%mod+(D[n-1]+D[n-3])%mod+C2[n-3])%mod;
	C2[n] = (a(n-1)+a(n-2)+d(n-1)+d(n-3)+c2(n-3))%mod;
	return C2[n];
}

ull d(int n){
	if (n<1){
		return 0;
	}
	if (D[n]!=-1){
		return D[n];
	}
	// if (A[n]==-1) A[n] = a(n);
	// if (B[n-1]==-1) B[n-1] = b(n-1);
	// return (B[n-1]+A[n])%mod;
	D[n] = (b(n-1)+a(n))%mod;
	return D[n];
}


int main() {
	sints(n,m)
	if (m==1){
		print(1)
	}
	elif (m==2){
		print(case2(n))
	}
	elif (m==3){
		memset (A,-1,sizeof(A));
		memset (B,-1,sizeof(A));
		memset (C1,-1,sizeof(A));
		memset (C2,-1,sizeof(A));
		memset (D,-1,sizeof(A));
		printf("%lld\n", a(n));
	}

	return 0;
}