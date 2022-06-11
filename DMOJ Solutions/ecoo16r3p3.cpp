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

set<string> dictionary;
int dp[2002];
//dp[i] stores the number of capitalizations needed for the first i characters

/*
idea is that instead of iterating over every word in the dictionary at every index,
iterate over all the substrings at the indices that are reachable, and try to find them in the dictionary in log(n) time
*/

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    int n;
    string word;
    cin >> n;
    f(n){
    	cin >> word;
    	dictionary.insert(word);
    }
    string s;
    int inf = 0x3f3f3f3f;
    f(10){
    	cin >> s;
    	memset(dp,0x3f,sizeof(dp));
    	dp[0] = 0;
    	int sl = s.length();
    	f(sl){
    		if (dp[i]<inf){
    			ff(sl-i+1){
    				if (dictionary.find(s.substr(i,j)) != dictionary.end()){
    					//if substr exists in dic
    					dp[i+j] = min(dp[i+j],dp[i]+1);
	    			}
	    		}
    		}
    	}
    	cout << dp[sl] - 1;n()
    }
	return 0;
}