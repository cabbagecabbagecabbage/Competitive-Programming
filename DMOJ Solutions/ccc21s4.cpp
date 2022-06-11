// debugging for friend

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define scan(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;
using namespace std;

typedef pair<int, int> pii;

int n,w,d,x,y;
int di[200001], ord[200001];
vector<int> paths[200001];

void bfs(){
	queue<int> q;
	q.push(n);
	memset(di,0x3f,sizeof(di));
	di[n] = 0;
	while (!q.empty()){
		int node = q.front(); q.pop();
		for (int x: paths[node]){
			if (di[x] > di[node] + 1){
				di[x] = di[node] + 1;
				q.push(x);
			}
		}
	}
}

int main(){
	scan(n); scan(w); scan(d); 
    for (int i = 0, a, b; i < w; i ++){
        scan(a); scan(b);
        paths[b].push_back(a);
    }

    multiset<int> ans;
    bfs();

    for (int i = 0; i < n; i ++){
        scan(ord[i+1]);
        ans.emplace(di[ord[i+1]]+i);
    }
    //ord[position] = station;
    //di[x] -> #from x to n using walkway
    while (d--){
        scan(x); scan(y);
        if (di[ord[x]] != 0x3f3f3f3f){
	        ans.erase(ans.find(di[ord[x]] + x-1));
	        ans.insert(di[ord[x]] + y-1);
	    }
	    if (di[ord[y]] != 0x3f3f3f3f){
	        ans.erase(ans.find(di[ord[y]] + y-1));
	        ans.insert(di[ord[y]] + x-1);
	    }
        swap(ord[x],ord[y]);
        cout << *(ans.begin()) << "\n";
    }



    return 0;
}

//cout << fixed << setprecision(2) << (double)ans/n;