/*
not my code
*/

#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>

#define scan(x) while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=x*10+_-'0')
char _;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 5;
int n,q; ll arr[maxn], s[2*maxn];

ll query(int l, int r){
	ll res = LLONG_MAX;
	for (l += maxn, r += maxn; l < r; l /= 2, r /= 2){
		if (l % 2) res = min(res, s[l++]);
		if (r % 2) res = min(res, s[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
    	cin >> s[i+maxn];
    }
    for (int i = maxn-1; i > 0; --i){
    	s[i] = min(s[2*i], s[2*i+1]);
    }
    while (q--){
        ll v;
        int a, b;
       	cin >> v >> a >> b;
        while (a <= b){
        	int lo = a, hi = b, ans = -1;
        	while (lo <= hi){
        		int mid = (lo + hi) / 2;
        		if (query(a,mid+1) <= v){
        			ans = mid;
        			hi = mid - 1;
        		}
        		else{
        			lo = mid + 1;
        		}
        	}
        	if (ans == -1) break;
        	else{
        		v %= s[maxn+ans];
        		a = ans + 1;
        	}
        }
        cout << v << "\n";
    }
    return 0;
}