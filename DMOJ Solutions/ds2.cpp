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

int parent[100001];

int sfind(int v){
	if (parent[v]==v) return v;
	parent[v] = sfind(parent[v]);
	return parent[v];
}

int sunion(int a, int b){
	int pa = sfind(a);
	int pb = sfind(b);
	if (pa==pb) return 0;
	parent[pa] = pb;
	return 1;
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    int n, m;
    cin >> n >> m;
    f(n) parent[i] = i;

    int a,b;
    int count = 0;
    vector<int> vec;
    f(m){
    	cin >> a >> b;
    	if (sfind(a) != sfind(b)){
    		sunion(a,b);
    		vec.push_back(i+1);
    		count += 1;
    	}
    }
    if (count < n-1){
    	cout << "Disconnected Graph" << "\n";
    }
    else{
    	f(n-1){
    		cout << vec[i] << "\n";
    	}
    }

	return 0;
}