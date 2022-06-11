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
#define sintss(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define print(a) printf("%d\n", a);
#define prints(a) printf("%s",a);
#define _() printf(" ");
#define n() printf("\n");

int ninf = INT_MIN;
int inf = INT_MAX;

int m, n;
int r1, c1, r2, c2;
int op, r, c, x;

int board[3005][3005] = {};
int whitetree[3005][3005] = {};
int blacktree[3005][3005] = {};


void update(int arr[3005][3005], int x, int y, int add) {
	//note that x is the row, y is the column
	int y1;
	while (x <= 3002) {
		y1 = y;
		while (y1 <= 3002) {
			arr[x][y1] += add;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int sum(int arr[3005][3005], int x, int y) {
	//rect sum from arr[1][1] to arr[x][y]
	int res = 0;
	while (x > 0) {
		int y1 = y;
		while (y1 > 0) {
			res += arr[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return res;
}

int main() {
	sints(m, n)
	while (1) {
		sint(op)
		if (op == 0) {
			break;
		}
		elif (op == 1) {
			//update
			sintss(r, c, x)
			int inc = x - board[r][c];
			board[r][c] = x;

			if ((r + c) % 2) update(blacktree, r, c, inc);
			else update(whitetree, r, c, inc);
		}
		else {
			sints(r1, c1)
			sints(r2, c2)
			int s = 0;
			if ((r1+c1)%2){
				//black
				s+=sum(blacktree,r2,c2)-sum(blacktree,r2,c1-1)-sum(blacktree,r1-1,c2)+sum(blacktree,r1-1,c1-1);
				s-=sum(whitetree,r2,c2)-sum(whitetree,r2,c1-1)-sum(whitetree,r1-1,c2)+sum(whitetree,r1-1,c1-1);
			}
			else{
				//white
				s-=sum(blacktree,r2,c2)-sum(blacktree,r2,c1-1)-sum(blacktree,r1-1,c2)+sum(blacktree,r1-1,c1-1);
				s+=sum(whitetree,r2,c2)-sum(whitetree,r2,c1-1)-sum(whitetree,r1-1,c2)+sum(whitetree,r1-1,c1-1);
			}
			print(s)
		}
	}
}