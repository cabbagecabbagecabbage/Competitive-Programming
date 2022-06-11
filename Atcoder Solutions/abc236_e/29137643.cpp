#include <bits/stdc++.h>
using namespace std;
#define double long double

vector<double> a;

bool avgok(double avg){
	vector<double> b;
	for (int i = 0; i < a.size(); ++i){
		b.emplace_back(a[i] - avg);
	}
	double f = 0, g = 0; //f took last, g took before
	for (int i = 0; i < b.size(); ++i){
		double newf = max(g + b[i], f + b[i]);
		double newg = f;
		f = newf;
		g = newg;
	}
	return max(f,g) >= 0;
}

bool medok(int med){
	vector<int> b;
	for (int i = 0; i < a.size(); ++i){
		b.emplace_back((int) a[i] >= med ? 1 : -1);
	}
	int f = 0, g = 0;
	for (int i = 0; i < b.size(); ++i){
		double newf = max(g + b[i], f + b[i]);
		double newg = f;
		f = newf;
		g = newg;
	}
	return max(f,g) > 0;
}

int32_t main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		double k; cin >> k;
		a.emplace_back(k);
	}
	{
		double lo = 0, hi = 1e9 + 5, avg;
		while (hi - lo >= 1e-6){
			double mid = (lo + hi) / 2;
			if (avgok(mid)){
				avg = mid;
				lo = mid;
			}
			else hi = mid;
		}
		cout << fixed << setprecision(10) << avg << "\n";
	}
	{
		int lo = 0, hi = 1e9 + 5, med;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (medok(mid)){
				med = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		cout << med << "\n";
	}
	return 0;
}