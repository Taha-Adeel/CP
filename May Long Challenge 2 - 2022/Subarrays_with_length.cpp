#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for(int a = 0; a < c; ++a)
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		vector<int> A(N);
		map<int, vector<int>> num_indices;
		FOR(i, N){
			cin >> A[i];
			num_indices[A[i]].push_back(i);
		}

		ll answer = 0;
		for(auto& num: num_indices){
			int cur_value = num.first;
			ll num_of_subarrays = 0;
			int start_pos = max(num.second[0] - (cur_value - 1), 0);
			int end_pos = min(num.second[0] + (cur_value - 1), N-1);

			for(auto i: num.second){
				if(i <= end_pos){
					end_pos = min(i + (cur_value - 1), N - 1);
				}
				else{
					num_of_subarrays += end_pos - start_pos + 1 - (cur_value - 1);

					start_pos = max(i - (cur_value - 1), 0);
					end_pos = min(i + (cur_value - 1), N - 1);
				}
			}
			num_of_subarrays +=  end_pos - start_pos + 1 - (cur_value - 1);
			answer += num_of_subarrays;
		}

		cout << answer << nl;
	}

	return 0;
}