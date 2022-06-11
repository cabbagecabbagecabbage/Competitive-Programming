#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
process queries in reverse
coordinate compress
dsu to merge 2 segments
parent of each set also stores a variable nxt, the first compressed x that the segment doesnt contain
answer at xi is idxtonum[nxt[find(xi)]] - idxtonum[find(xi)]
*/

const int nax = 2e5 + 5;
int l,q,parent[nax],nxt[nax];
bool split[nax];
pair<int,int> queries[nax];
int idxtonum[nax];
gp_hash_table<int,int> numtoidx;

int Find(int node){
	return parent[node] = (node == parent[node] ? node : Find(parent[node]));
}

void Merge(int a, int b){
	a = Find(a), b = Find(b);
	if (a == b) return;
	nxt[b] = nxt[a];
	parent[a] = b;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> q;
	int idx = 0;
	idxtonum[idx++] = 0; split[0] = true;
	for (int i = 0; i < q; ++i){
		cin >> queries[i].first >> queries[i].second;
		idxtonum[idx++] = queries[i].second;
	}
	idxtonum[idx++] = l;
	sort(idxtonum, idxtonum + idx);
	for (int i = 0; i < idx; ++i) numtoidx[idxtonum[i]] = i;
	for (int i = 0; i < q; ++i){
		if (queries[i].first == 1) split[numtoidx[queries[i].second]] = true;
	}
	int curnxt = idx-1;
	for (int i = idx-2; i >= 0; --i){
		if (split[i]){
			parent[i] = i;
			nxt[i] = curnxt;
			curnxt = i;
		}
		else parent[i] = i-1;
		// cout << idxtonum[i] << " " << i << " " << parent[i] << "\n";
	}
	vector<int> ans;
	for (int i = q-1; i >= 0; --i){
		if (queries[i].first == 1){
			Merge(numtoidx[queries[i].second], numtoidx[queries[i].second]-1);
		}
		else {
			int markp = Find(numtoidx[queries[i].second]);
			ans.push_back(idxtonum[nxt[markp]] - idxtonum[markp]);
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i){
		cout << ans[i] << "\n";
	}
	return 0;
}