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

/*
for every suffix of the first word, calculate the hash value in O(n)
for every prefix of the second word, calculate the hash value in O(n)

for a length i form 0 to the min(length of first, length of second)
take the hash value of the substring of length i starting from the end of the first string
take the hash value of the substring of length i starting form the beginning of the second string
if equal, set ans to that but keep going

finally, concatenate string1 and string 2 with prefix of length repeat chopped off (substr is easier to do this way)
*/

const int base = 37;
const long long mod = 44654641650887;

string suf,pre;
long long power[1000005];
long long hash1[1000005], hash2[1000005];

void computehash(int upto){
	power[0] = 1;
	f2(1,upto+1){
		power[i] = (power[i-1]*base)%mod;
	}
}

int ord(char s){
	return s - 'A';
}

int main() {
	// cin.sync_with_stdio(0);
	// cin.tie(0);
	cin >> suf >> pre;
	int l1 = suf.length();
	int l2 = pre.length();
	computehash(max(l1,l2));

	hash1[0] = ord(suf[l1-1]);
	//calculate hash value of suffixes
	f2(1,l1){
		hash1[i] = (hash1[i-1]+ord(suf[l1-i-1])*power[i])%mod;
	}

	hash2[0] = ord(pre[0]);
	//calculate hash value of prefixes
	f2(1,l2){
		hash2[i] = ((hash2[i-1]*base)%mod + ord(pre[i]))%mod;
	}
	// f(10){
	// 	cout << hash1[i] << " " << hash2[i] << endl;
	// }
	int repeat = 0;
	f(min(l1,l2)){
		if (hash1[i] == hash2[i]) repeat = i+1;
	}
	cout << suf+pre.substr(repeat);n()
    
	return 0;
}