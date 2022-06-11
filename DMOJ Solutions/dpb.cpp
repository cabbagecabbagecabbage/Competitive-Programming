#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
	int cost[101000];
	int minlis[101000];
	int first,second;

	cin >> n >> k;

	for (int i=0; i<n; i++){
		cin >> cost[i];
	}

	minlis[0] = cost[0];
	for (int i=1; i<k+1; i++){
		minlis[i] = abs(cost[0]-cost[i]);
	}
	
	// for (int i=0; i<k+1; i++){
	// 	cout << minlis[i] << " ";
	// }
	// cout <<endl;

	long min;
	int dist;
	for (int i=k+1; i<n; i++){
		min = 1000000000;
		for (int j=1; j<k+1; j++){
			dist = minlis[i-j] + abs(cost[i-j]-cost[i]);
			if (dist < min){
				min = dist;
			}			
		}
		minlis[i] = min;
	}

	cout << minlis[n-1] << endl;


	// for (int i=0; i<n+1; i++){
	// 	cout << minlis[i] << " ";
	// }
	// cout <<endl;
	return 0;
}