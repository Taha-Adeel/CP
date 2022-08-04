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

		vector<int> a(n);
		FOR(i, n)
			cin >> a[i];

		vector<int> reductions_req(n);
		int num_odds = 0;
		FOR(i, n){
			int counter = 0;
			int mask = 1;
			while((a[i] & mask) == 0){
				mask <<= 1;
				counter++;
			}
			reductions_req[i] = counter;
			if(counter == 0)
				num_odds++;
		}
		int min_reductions_req = *min_element(reductions_req.begin(), reductions_req.end());
		int answer;
		if(min_reductions_req == 0){
			answer = n - num_odds;
		}
		else{
			answer = min_reductions_req + n - (num_odds + 1);
		}

		cout << answer << nl;
	}

	return 0;
}