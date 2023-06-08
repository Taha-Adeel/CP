#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)

using ll  = long long int;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

bool comp(const pair<int,ll>& a, const pair<int,ll>& b)
{
	if(a.first < b.first){
		return true;
	} else if (a.first > b.first){
		return false;
	} else {
		if(a.second < b.second){
			return false;
		} else {
			return true;
		}
	}
}

void solve(){
	int n; cin >> n;
	vector<pair<int, ll>> a;
	for(int i = 0; i < n; i++){
		int u; ll v; cin >> u >> v;
		a.emplace_back(u,v);
	}
	sort(a.begin(), a.end(), comp);
	ll ans = 0;
	
}

int main(){
	FAST;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		solve();
		cout << '\n';
	}
	
	return 0;
}