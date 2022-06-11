/*
explanation: https://codeforces.com/blog/entry/13442
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

int tn,tk;
int ql, qr, th;
int top[2000005], tleft[2000005], tright[2000005], theight[2000005], tfinalHeight[2000005];

int tree[8000005][2]; //low,high

const int inf = INT_MAX;

void updatechildren(int v){
	//note that if the parent is [inf,0] then none of these changes would actually apply
	int left = 2*v;
	int right = 2*v+1;
	tree[left][0] = min(tree[left][0],tree[v][0]);
	tree[left][0] = max(tree[left][0],tree[v][1]);
	tree[left][1] = max(tree[left][1],tree[v][1]);
	tree[left][1] = min(tree[left][1],tree[v][0]);

	tree[right][0] = min(tree[right][0],tree[v][0]);
	tree[right][0] = max(tree[right][0],tree[v][1]);
	tree[right][1] = max(tree[right][1],tree[v][1]);
	tree[right][1] = min(tree[right][1],tree[v][0]);

	tree[v][0] = inf;
	tree[v][1] = 0;
}


void remove(int v, int l, int r, int t){
	if (r<ql || l>qr){
		return;
	}
	if (ql<=l && r<=qr){
		tree[v][1] = min(t,tree[v][1]);
		tree[v][0] = min(tree[v][0],t);
		return;
	}
	int m = (l + r) / 2;
	updatechildren(v);
	remove(v*2,l,m,t);
	remove(v*2+1,m+1,r,t);
}

void add(int v, int l, int r, int t){
	if (r<ql || l>qr){
		return;
	}
	if (ql<=l && r<=qr){
		tree[v][0] = max(t,tree[v][0]);
		tree[v][1] = max(tree[v][1],t);
		return;
	}
	int m = (l + r) / 2;
	updatechildren(v);
	add(v*2,l,m,t);
	add(v*2+1,m+1,r,t);
}

void solve(int v, int l, int r){
	if (l==r){
		tfinalHeight[l] = min(tree[v][0],tree[v][1]); //reached from left to right
		return;
	}
	else{
		int m = (l + r) / 2;

		updatechildren(v);

		solve(v*2,l,m);
		solve(v*2+1,m+1,r);
	}
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	for (int i=0; i<4*n; i++){
    	tree[i][0] = inf;
    	tree[i][1] = 0;
    }
    for (int i=0; i<k; i++){
        int tempop = op[i];
        ql = left[i];
        qr = right[i];
        int th = height[i];
        if (tempop==1){
            add(1,0,n-1,th); 
        }
        if (tempop==2){
            remove(1,0,n-1,th);
        }
    }
    solve(1,0,n-1);
    for (int i=0; i<n; i++) finalHeight[i] = tfinalHeight[i];
}
int main(){
	return 0;
}