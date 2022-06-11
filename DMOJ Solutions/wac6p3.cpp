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
#define llinf 0x3f3f3f3f3f3f3f3f
#define infb 0x3f
#define elif else if
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


/*

*/
const int nax = 2e5+5;
int parent[nax];
int size[nax];
// int indexofnum[nax];
unordered_map<long long, int> indexofnum;
int n;
ll numbers[nax], sorted[nax];
int hardestToReach[nax]; //maps from index to the hardest index to reach from the index (to become sorted)
#define htr hardestToReach


int Find(int node){
	return parent[node] == node ? node : parent[node] = Find(parent[node]);
}

void Merge(int a, int b){
	a = Find(a); b = Find(b);
	if (a != b){
		if (size[a] > size[b]) swap(a,b);
		parent[a] = b;
		size[b] += size[a];
	}
}


bool solve(long long length){
	f(nax) parent[i] = i, size[i] = 1;
	f(n-1){
		if (sorted[i+1] - sorted[i] <= length){
			Merge(i,i+1); //draw edge between indices
		}
	}
	f(n){
		if (htr[i] != -1){
			if (Find(i) != Find(htr[i])){
				return false;
			}
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	in(n);
	f(n){
		in(numbers[i]);
		sorted[i] = numbers[i];
		indexofnum[numbers[i]] = i;
	}
	
	sort(sorted, sorted + n);
	mem(htr,-1);
	f(n){
		if (numbers[i] != sorted[i]){
			int unsortedindex = indexofnum[sorted[i]];
			//map index of sorted[i] in numbers -> index of numbers[i] in numbers
			if (htr[unsortedindex] == -1) htr[unsortedindex] = i;
			else{
				if (abs(numbers[htr[i]] - sorted[i]) < abs(numbers[i] - sorted[i])){
					htr[unsortedindex] = i;
				}
			}
		}
	}
	
	ll ans = llinf;
	ll lo = 0;
	ll hi = 1e18;
	while (lo <= hi){
		ll mid = (lo + hi) / 2;
		if (solve(mid)){
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else lo = mid + 1;
	}
	
	out(ans);
			

	return 0;
}




















//trailing lines ftw