// note i already solved problem, taking dijkstra function from ADMathNoob for learning purposes
#include <bits/stdc++.h>
using namespace std;
#define f(a) for (int i=0; i<a; i++)
#define ff(a) for (int j=0; j<a; j++)
#define f2(a,b) for (int i=a; i<b; i++)
#define ff2(a,b) for (int j=a; j<b; j++)
#define fb(a) for (int i=a-1; i>=0; i--)
#define elif else if
#define n() cout << "\n";
typedef vector<int> vi;
typedef pair<int,int> pii;

int inf = INT_MAX;
int n,m;
vector<pii> adj[1001];

void dijkstra(int start) {
    int distances[1001];
    fill(distances, distances + 1001, inf);
    bool visited[1001] = {};
    priority_queue<pii> q;

    q.push({0, start});
    distances[start] = 0;

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : adj[a]) {
            int b, w;
            tie(b, w) = u; //break down the pairs
            int newcost = distances[a] + w;
            if (newcost < distances[b]) {
                distances[b] = newcost;
                q.push({-distances[b], b});
            }
        }
    }
    f2(1,n+1){
        if (distances[i]==inf) cout << -1 << "\n";
        else cout << distances[i] << "\n";
    }
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    f(m){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(1);
    return 0;
}