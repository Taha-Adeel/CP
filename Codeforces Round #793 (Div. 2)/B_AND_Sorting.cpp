#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		vector<p_ii> p_i(n);
		FOR(i, n){
			int p;
			cin >> p;
			p_i[i] = {p, i};
		}
		sort(p_i.begin(), p_i.end());

		vector<p_ii> to_swap;
		FOR(i, n){
			if(p_i[i].second != i)
				to_swap.push_back(p_i[i]);
		}
		int answer = to_swap[0].first;
		for(auto& p: to_swap){
			answer &= p.first;
		}
		cout << answer << nl;
	}

	return 0;
}