#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
template<typename T>void out(T x){cout<<x<<"\n";}
template<typename T>void sp(T x){cout<<x<<" ";}
template<typename T,typename...A>void out(T x,A...a){sp(x),out(a...);}
template<typename T>void out(vector<T>& v){for(T x:v)sp(x);out("");}

const int mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;

/*
diagonals right
*/

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int h,w; cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; ++i) cin >> a[i];
	int ans = 1;
	//top row
	for (int j = 0; j < w; ++j){
		bool red = false, blue = false;
		for (int y=0,x=j; y < h and x >= 0; ++y,--x){
			if (a[y][x] == 'B') blue = true;
			if (a[y][x] == 'R') red = true;
		}
		if (red and blue){
			out(0);
			return 0;
		}
		if (!red and !blue){
			ans *= 2;
			ans %= mod;
		}
	}
	//left column
	for (int i = 1; i < h; ++i){
		bool red = false, blue = false;
		for (int y=i,x=w-1; y < h and x >= 0; ++y,--x){
			if (a[y][x] == 'B') blue = true;
			if (a[y][x] == 'R') red = true;
		}
		if (red and blue){
			out(0);
			return 0;
		}
		if (!red and !blue){
			ans *= 2;
			ans %= mod;
		}
	}
	out(ans);
	return 0;
}