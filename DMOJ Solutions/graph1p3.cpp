#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define qq ;cout << "\n";
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,startnode;
int matrix[11][11];
int visited[11];
int cycles = 0;
/*
for every node, do a dfs to try to find a cycle

keep track of the start node that we started on
set visited[vertex] to true when entering the function to avoid cycling
if the next vertice is the start node then a cycle is found
else go to the node if its not visited
at the end of the recursive function, set visited[vertex] to false again, to allow other paths to reuse nodes

after calling dfs, set visited[startnode] to true again because all the cycles related to this node has been found already, so dont go to this node (avoids double counting)
*/

void dfs(int vertex){
	visited[vertex] = 1;
	f(n){
		if (matrix[vertex][i]){
			if (i==startnode){
				cycles++;
			}
			elif (!visited[i]){
				dfs(i);
			}
		}
	}
	visited[vertex] = 0;
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
    cin >> n;
    f(n){
    	ff(n) cin >> matrix[i][j];
    }
    

    f(n){
    	startnode = i;
    	dfs(i);
    	visited[i] = 1;
    }

    cout << cycles qq
	return 0;
}