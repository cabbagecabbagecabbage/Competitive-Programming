#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define in(a) cin >> a
#define ibl(a,b) cin >> a >> b
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
#define infb 0x3f
#define elif else if
#define pb push_back
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
 
/*
 
*/
int t;
string a,b;
int al,bl;
int main() {
 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 in(t);
 while(t--){
  ibl(a,b);
  al = a.length();
  bl = b.length();
  string ares = "",bres = "";
  int m = (al > bl) ? al : bl;
     do
     {
         if (m % al == 0 && m % bl == 0)
         {
             break;
         }
         else
             ++m;
     } while (true);
  f(m / al) ares += a;
  f(m / bl) bres += b;
  if (ares == bres) out(ares);
  else out(-1);
 }
 
 
 
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//trailing lines ftw