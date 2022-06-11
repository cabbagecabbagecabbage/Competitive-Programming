#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define in2(a,b) cin >> a >> b
#define in3(a,b,c) cin >> a >> b >> c
#define out(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define f(a) for (int i = 0; i < a; i++)
#define ff(a) for (int j = 0; j < a; j++)
#define f2(a, b) for (int i = a; i < b; i++)
#define ff2(a, b) for (int j = a; j < b; j++)
#define fb(a) for (int i = a - 1; i >= 0; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*

*/
int visited[1000][1000];
int shift = 500;

int v(int num){return -1*num;}
int h(int num){return num + shift;}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	visited[v(-1)][h(0)] = 1;
	
	visited[v(-2)][h(0)] = 1;
	
	visited[v(-3)][h(0)] = 1;
	visited[v(-3)][h(1)] = 1;
	visited[v(-3)][h(2)] = 1;
	visited[v(-3)][h(3)] = 1;
	visited[v(-3)][h(5)] = 1;
	visited[v(-3)][h(6)] = 1;
	visited[v(-3)][h(7)] = 1;

	visited[v(-4)][h(3)] = 1;
	visited[v(-4)][h(5)] = 1;
	visited[v(-4)][h(7)] = 1;
	
	visited[v(-5)][h(-1)] = 1;
	visited[v(-5)][h(3)] = 1;
	visited[v(-5)][h(4)] = 1;
	visited[v(-5)][h(5)] = 1;
	visited[v(-5)][h(7)] = 1;
	
	visited[v(-6)][h(-1)] = 1;
	visited[v(-6)][h(7)] = 1;
	
	visited[v(-7)][h(-1)] = 1;
	visited[v(-7)][h(0)] = 1;
	visited[v(-7)][h(1)] = 1;
	visited[v(-7)][h(2)] = 1;
	visited[v(-7)][h(3)] = 1;
	visited[v(-7)][h(4)] = 1;
	visited[v(-7)][h(5)] = 1;
	visited[v(-7)][h(6)] = 1;
	visited[v(-7)][h(7)] = 1;
	
	
	int currow = -5, curcol = -1;
	
	char op;
	int dist;
	int danger = 0;
	while (1){
		in2(op,dist);
		if (op == 'q') return 0;
		if (op == 'l'){
			f(dist){
				curcol--;
				int& vis = visited[v(currow)][h(curcol)];
				if (!vis) vis = 1;
				else{
					danger = 1;
				}
			}
		}
		if (op == 'd'){
			f(dist){
				currow--;
				int& vis = visited[v(currow)][h(curcol)];
				if (!vis) vis = 1;
				else{
					danger = 1;
				}
			}
		}
		if (op == 'r'){
			f(dist){
				curcol++;
				int& vis = visited[v(currow)][h(curcol)];
				if (!vis) vis = 1;
				else{
					danger = 1;
				}
			}
		}
		if (op == 'u'){
			f(dist){
				currow++;
				int& vis = visited[v(currow)][h(curcol)];
				if (!vis) vis = 1;
				else{
					danger = 1;
				}
			}
		}
		if (danger){
			cout << curcol << " " << currow << " DANGER" << endl;
			return 0;
		}
		cout << curcol << " " << currow << " safe" << endl;
	}


	return 0;
}




















//trailing lines ftw