#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
using ll = long long int;
using p_ii = pair<int,int>;

int main(){
	int T;
	cin >> T;
	while(T--){
		int answer = 0;
		vector<p_ii> p(3);
		FOR(i,3){
			cin >> p[i].first >> p[i].second;
		}
		if(p[0].second == p[1].second && p[2].second < p[0].second)
			answer+= abs(p[0].first - p[1].first);
		else if(p[1].second == p[2].second && p[0].second < p[1].second)
			answer+= abs(p[2].first - p[1].first);
		else if(p[2].second == p[0].second && p[1].second < p[0].second)
			answer+= abs(p[2].first - p[0].first);

		cout << answer << '\n';
	}

	return 0;
}