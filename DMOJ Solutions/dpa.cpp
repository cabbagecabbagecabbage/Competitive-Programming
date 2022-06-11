#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
	int cost[100003];
	int minlis[100003];
	int first,second;
	string hline;

	cin >> n;

	for (int i=0; i<n; i++){
		cin >> cost[i];
	}

	minlis[0] = cost[0];
	minlis[1] = abs(cost[1]-cost[0]);
	minlis[2] = abs(cost[2]-cost[0]);

	for (int i=1; i<n; i++){
		first = abs(cost[i]-cost[i+1])+minlis[i];
		if (first < minlis[i+1]){
			minlis[i+1] = first;
		}

		second = abs(cost[i]-cost[i+2])+minlis[i];
		minlis[i+2] = second;
	}

	cout << minlis[n-1] << endl;
	return 0;
}