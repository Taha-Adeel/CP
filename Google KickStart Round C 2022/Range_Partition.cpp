#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;

void partition(ll N, ll PartitionSum, vector<ll>& answer){
	if(PartitionSum == 0 || N == 0)
		return;

	if(N > PartitionSum)
		partition(N-1, PartitionSum, answer);
	else{
		answer.push_back(N);
		partition(N-1, PartitionSum - N, answer);
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		ll N, X, Y;
		cin >> N >> X >> Y;


		ll total_sum = (N * (N + 1))/2;
		vector<ll> answer;
		if((total_sum)%(X + Y) == 0){
			ll S_x =  (X * total_sum)/(X + Y);
			
			partition(N, S_x, answer);
			sort(answer.begin(),answer.end());

			cout << "Case #" << t + 1 << ": POSSIBLE" << nl;
			cout << answer.size() << nl;
			for(auto i: answer){
				cout << i << ' ';
			}
			cout << nl;
		}
		else
			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << nl;
	}

	return 0;
}