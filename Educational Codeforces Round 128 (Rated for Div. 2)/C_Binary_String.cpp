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
		string bs;
		cin >> bs;

		int cost = 0;
		for(auto c: bs){
			if(c == '0')
				cost++;
		}

		vector<p_ii> cost_reduced_fi(bs.size()+1);
		vector<p_ii> cost_reduced_bi(bs.size()+1);
		cost_reduced_fi[0].first = 0;
		cost_reduced_fi[0].second = 0;
		cost_reduced_bi[0].first = 0;
		cost_reduced_bi[0].second = 0;
		for(int i = 1; i <= bs.length(); ++i){
			if(bs[i - 1] == '0')
				cost_reduced_fi[i].first = cost_reduced_fi[i - 1].first - 1;
			else
				cost_reduced_fi[i].first = cost_reduced_fi[i - 1].first + 1;

			if(cost_reduced_fi[i].first < cost_reduced_fi[i - 1].second)
				cost_reduced_fi[i].second = cost_reduced_fi[i].first;
			else
				cost_reduced_fi[i].second = cost_reduced_fi[i - 1].second;
		}
		int j=1;
		for(int i = bs.length() - 1; i >= 0; --i){
			if(bs[i] == '0')
				cost_reduced_bi[j].first = cost_reduced_bi[j - 1].first - 1;
			else
				cost_reduced_bi[j].first = cost_reduced_bi[j - 1].first + 1;

			if(cost_reduced_bi[j].first < cost_reduced_bi[j - 1].second)
				cost_reduced_bi[j].second = cost_reduced_bi[j].first;
			else
				cost_reduced_bi[j].second = cost_reduced_bi[j - 1].second;
			
			j++;
		}

		int min_total_reduced = 0;
		for(int i = 0; i <= bs.length(); ++i){
			int total_reduced = cost_reduced_fi[i].second + cost_reduced_bi[bs.length() - i].second;

			if(total_reduced < min_total_reduced)
				min_total_reduced = total_reduced;
		}

		cout << cost + min_total_reduced << nl;
	}

	return 0;
}