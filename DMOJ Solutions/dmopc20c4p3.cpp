#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

/*
insert all horizontal lines into order statistic tree
2 possible events:
	vertical line:
		query for the number of elements in the set that have y coordinate less than or equal to the current vertical line by finding the order statistic of {y+1,-1} which is strictly between the greatest {y,id} and {y+1,id}
	end of horizontal line:
		remove the horizontal line from the set by value
*/

struct event{
	int type,x,y,id;
	//type 1. vertical line
	//type 2. end of horizontal line;
};
 
bool c(event a, event b){
	//endpoint intersection counts; make sure to process vertical line before removing horizontal line
	return (a.x == b.x ? a.type < b.type : a.x < b.x);
}

int n,m,id = 0;
vector<event> events;
tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ost;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	while (n--){
		int x,y; cin >> x >> y;
		ost.insert({y,++id});
		events.push_back({2,x,y,id});
	}
	while (m--){
		int x,y; cin >> x >> y;
		events.push_back({1,x,y,-1}); //no id
	}
	sort(events.begin(),events.end(),c);
	int ans = 0;
	for (event e: events){
		if (e.type == 1){
			ans += (ost.order_of_key({e.y+1,-1}));
		}
		if (e.type == 2){
			ost.erase({e.y,e.id});
		}
	}
	cout << ans << "\n";
	return 0;
}