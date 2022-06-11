#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
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
#define print2(a,b) printf("%d %d\n", a, b);
#define n() printf("\n");

vector<int> graph[10005];
vector<int> pgraph[10005]; //backwards

int useful[10005]={};
int puseful[10005]={};

void prune(int i){
	if (useful[i]) return;
	useful[i] = 1;
	for (int k: graph[i]) prune(k);
}
void prune2(int i){
	if (puseful[i]) return;
	puseful[i] = 1;
	for (int k: pgraph[i]) prune2(k);
}

/*basic idea:
white: unchecked
gray: checking
black: checked

if u encounter a gray while checking, cycle detected
*/
int colour[10005]={}; //0,1,2 -> white, gray, black
int memo[10005]={};

int big = 0;

long long solve(int i){
	if (colour[i]==2) return memo[i];
	if (colour[i]==1) return -1;
	colour[i] = 1;
	memo[i] = 0;
	if (i==1) memo[i] = 1;
	for (int k: graph[i]){
		if (useful[k]&&puseful[k]){
			long long res = solve(k);
			if (res==-1) return -1;
			memo[i]+=solve(k);
			if (!big && memo[i]!=memo[i]%1000000000){
				big = 1;
			}
			memo[i]%=1000000000;
		}
	}
	colour[i] = 2;
	return memo[i];
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
	int n,m;
	int a,b;
	cin >> n >> m;
	f(m){
		cin >> a >> b;
		a-=1; b-=1;
		graph[a].push_back(b);
		pgraph[b].push_back(a);
	}
	prune(0);
	prune2(1);

	int res = solve(0);
	if (res==-1) cout << "inf" << "\n";
	else{
		res %= 1000000000;
		if (big){
			int leading = 9 - to_string(res).length();
		f(leading) cout << "0";
		}
		cout << res << "\n";
	}
    
	return 0;
}