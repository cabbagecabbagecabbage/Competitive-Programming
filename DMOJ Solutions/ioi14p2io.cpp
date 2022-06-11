#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ui(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;

int n,k;
int op, ql, qr, h;
int tree[8000005][2]; //low,high

const int inf = INT_MAX;

void updatechildren(int v){
	int left = v << 1;
	int right = left | 1;
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
	if (r<ql || l>qr) return;
	if (ql<=l && r<=qr){
		tree[v][1] = min(t,tree[v][1]);
		tree[v][0] = min(tree[v][0],t);
		return;
	}
	int m = (l + r)>> 1;
	updatechildren(v);
	remove(v*2,l,m,t);
	remove(v*2+1,m+1,r,t);
}

void add(int v, int l, int r, int t){
	if (r<ql || l>qr) return;
	if (ql<=l && r<=qr){
		tree[v][0] = max(t,tree[v][0]);
		tree[v][1] = max(tree[v][1],t);
		return;
	}
	int m = (l + r)>> 1;
	updatechildren(v);
	add(v*2,l,m,t);
	add(v*2+1,m+1,r,t);
}

void solve(int v, int l, int r){
	if (l==r){
		cout << min(tree[v][0],tree[v][1]) << "\n"; //reached from left to right
		return;
	}
	else{
		int m = (l + r)>> 1;
		updatechildren(v);
		solve(v*2,l,m);
		solve(v*2+1,m+1,r);
	}
}

int main(){
    ui(n);ui(k);
    for (int i=0; i<4*n; ++i){
    	tree[i][0] = inf;
    }
    for (int i=0; i<k; i++){
        ui(op);ui(ql);ui(qr);ui(h);
        if (op==1){
            add(1,0,n-1,h); 
        }
        else{
            remove(1,0,n-1,h);
        }
    }
    solve(1,0,n-1);
    return 0;
}