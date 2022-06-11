#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a;
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

void out(int num){
	int ans = 3;
	if (num <= 10){
		cout << ans + num*2 << endl;
		return;
	}
	cout << ans + 10*2 + (num-10) << endl;
}

/*

*/
bool compare(pii a, pii b){
	return a.first > b.first;
}

int V,E,P,D,R;
vector<pii> adj[100005];
int visited[100005];
int a,b,c;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(V)in(E)in(P)in(D)in(R)
	f(E){
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	
	//P to D
	priority_queue<pii, vector<pii>, decltype(&compare)> q(compare);//{dist,node}
	q.push(mp(0,P));
	int first,second;
	int found1 = 0, found2 = 0;
	while (!q.empty()){
		pii cur = q.top();
		q.pop();
		if (cur.second == D){
			first = cur.first;
			found1 = 1;
			break;
		}
		visited[cur.second] = 1;
		for (pii x: adj[cur.second]){
			if (!visited[x.first]){
				q.push(mp(x.second+cur.first,x.first));
			}
		}
	}
	
	if (!found1){
		cout << "Nooooooooo!!!" <<endl;
		return 0;
	}
		
	//D to R
	mem(visited,0);
	priority_queue<pii, vector<pii>, decltype(&compare)> q2(compare);//{dist,node}
	q2.push(mp(0,D));
	while (!q2.empty()){
		pii cur = q2.top();
		q2.pop();
		if (cur.second == R){
			second = cur.first;
			found2 = 1;
			break;
		}
		visited[cur.second] = 1;
		for (pii x: adj[cur.second]){
			if (!visited[x.first]){
				q2.push(mp(x.second+cur.first,x.first));
			}
		}
	}
	if (!found2){
		out(first);
		cout << "Yippee!!!" << endl;
		return 0;
	}
	out(first+second);
	return 0;
}




















//trailing lines ftw