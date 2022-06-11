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
int points[17][17], n;
long long sum[(1<<17)], f[(1<<17)];

//f[mask] stores the maximum amount of points by grouping  the rabbits in the subset (represented by the mask) in some way. (initialized as 1 group)
//sum[mask] stores the amount of points awarded if all the rabbits in the subset (represented by mask) are in one group

/*
the only reason that grouping all the rabbits into 1 group would not always be optimal is that you might gain negative points for putting rabbit i and rabbit j together.
*/

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    f(n){
        ff(n){
            cin >> points[i][j];
        }
    }
    //bitmasks as subsets, precalculate the sum of points received for each subset if all the rabbits in the subset were in 1 group. we can initialize f[mask] to the same value (though it is not necessarily optimal yet)

    for (int mask = 0; mask < (1 << n); ++mask) {
        //for every subset possible
        f(n){
            if (mask & (1 << i)) {
                // if the rabbit i is in mask
                ff2(i+1,n){
                    if (mask & (1 << j)) {
                        //if the rabbit j is also in mask (remember to not double count i and j)
                        sum[mask] += points[i][j]; //add to sum
                    }
                }
            }
        }
        f[mask] = sum[mask];
    }
    //dp
    f(1 << n){
        //i is the bitmask which always makes subsets using the first item, then the first 2, then the first 3, and so on, so that for j=(j-1) & i; i^j will have already been visited and optimized
        for (int j = i; j > 0; j = (j - 1) & i) {
            //traverse over all subsets of the set represented by i
            f[i] = max(f[i], f[i ^ j] + sum[j]); //try to group optimally
            //we dont have to worry about breaking down even further because the smaller groups have already been optimized
        }
    }
    cout << f[(1 << n) - 1];n()
    return 0;
}