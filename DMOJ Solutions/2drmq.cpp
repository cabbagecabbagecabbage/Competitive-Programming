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

// 1 ≤ N ≤ 1000
// 1 ≤ arr[i][j] ≤ 10^9 for 0 ≤ i,j ≤ N − 1
int table[11][1005][11][1005]; //comments say that small dimensions first is good for health
int logs[1005];
void computelogs() {
	logs[1] = 0;
	f2(2, 1005) {
		logs[i] = logs[i / 2] + 1;
	}
}

void init(std::vector<std::vector<int>> arr) {
	computelogs();

	//r1, c1 -> row, column of outer sparse table
	//r2, c2 -> row, column of inner sparse table
	//table[r1][c1][r2][c2]
	int i =0;
	int n = arr[0].size();
	for (int r1 = 0; r1 - 1 < logs[n]; r1++) {
		for (int c1 = 0; c1 + (1 << r1) - 1 < n; c1++) {
			for (int r2 = 0; r2 - 1 < logs[n]; r2++) {
				for (int c2 = 0; c2 + (1 << r2) - 1 < n; c2++) {
					if (r1 == 0 && r2 == 0) {
						table[r1][c1][r2][c2] = arr[c1][c2]; //(c1,c2) to (c1+2^0-1=c1,c2+2^0-1=c2) is the element itself
						
					}
					elif (r2 == 0) {
						table[r1][c1][r2][c2] = min(table[r1 - 1][c1][r2][c2], table[r1 - 1][c1 + (1 << (r1 - 1))][r2][c2]);
					}
					elif (r1 == 0) {
						table[r1][c1][r2][c2] = min(table[r1][c1][r2 - 1][c2], table[r1][c1][r2 - 1][c2 + (1 << (r2 - 1))]);
					}
					else {
						table[r1][c1][r2][c2] = min(min(table[r1 - 1][c1][r2 - 1][c2], 
													table[r1 - 1][c1 + (1 << (r1 - 1))][r2 - 1][c2]),
													min(table[r1 - 1][c1][r2 - 1][c2 + (1 << (r2 - 1))], 
													table[r1 - 1][c1 + (1 << (r1 - 1))][r2 - 1][c2 + (1 << (r2 - 1))]));
					}
					// print(table[r1][c1][r2][c2])
					// 	printf("%d %d %d %d\n", r1, c1, r2, c2);
				}
			}
		}
	}


	//table[r1][c1][r2][c2] contains the minimum element from (c1,c2) to (c1+2^r1-1,c2+2^r2-1)
}

int query(int a, int c, int b, int d) {
	int lenx = c - a + 1;
	int kx = logs[lenx];
	int leny = d - b + 1;
	int ky = logs[leny];
	// n()
	// printf("%d %d %d %d\n", kx, a, ky, b);
	// n()
	// print(table[kx][a][ky][b]) //top left
	// print(table[kx][a][ky][d + 1 - (1 << ky)]) //bottom left
	// print(table[kx][c + 1 - (1 << kx)][ky][b]) //top right
	// print(table[kx][c + 1 - (1 << kx)][ky][d + 1 - (1 << ky)]) //bottom right
	int min1 = min(table[kx][a][ky][b], table[kx][a][ky][d + 1 - (1 << ky)]);
	int min2 = min(table[kx][c + 1 - (1 << kx)][ky][b], table[kx][c + 1 - (1 << kx)][ky][d + 1 - (1 << ky)]);
	// n()
	return min(min1, min2);
}

// int main() {
// 	// 1 2
// 	// 3 4
// 	init({{1, 2}, {3, 4}});
// 	int a, b, c, d;
// 	sints(a, b)
// 	sints(c, d)
// 	print(query(a, b, c, d));
// 	return 0;
// }