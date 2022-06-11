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

int N,M;
int keep[100005]={};
int visited[100005] = {};
int randrest;
int rest;
vector<int> adj[100005];

int prune(int node){
	//prunes the tree
	visited[node] = 1;
	if (adj[node].size()==1&&node!=randrest){
		return keep[node];
	}
	int k = 0;
	for (int next:adj[node]){
		if (!visited[next]){
			if (prune(next)){
				k = 1;
			}
		}
	}
	if (k==1){
		keep[node]=1;
	}
	return keep[node];
}

pair<int,int> farthest(int start){
	queue<int> q;
	q.push(start);
	int cost[100005];
	f(100005){
		cost[i] = -1;
	}
	cost[start]=0;
	int m = 0;
	int far = start;
	int node;
	while (!q.empty()){
		node = q.front();
		q.pop();
		// print(node)
		if (cost[node]>m){
			m = cost[node];
			far = node;
		}
		int nextcost = cost[node]+1;
		for (int next:adj[node]){
			if (keep[next]&&cost[next]==-1){
				cost[next] = nextcost;
				q.push(next);
			}
		}
	}
	return make_pair(m,far);
}

int main() {
	sints(N,M)
	
	f(M){
		sint(rest)
		keep[rest] = 1;
		randrest = rest;
	}
	int a,b;
	f(N-1){
		sints(a,b)
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	prune(randrest);
	int ts=0;
	f(N){
		ts+=keep[i];
	}

	pair<int,int> p = farthest(randrest);

	p = farthest(p.second);

	print(2*(ts-1)-p.first)

	return 0;
}