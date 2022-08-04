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
		int N;
		cin >> N;

		int total_or = 0;
		int temp;
		FOR(i, N){
			cin >> temp;
			total_or |= temp;
		}

		int answer = 0;
		for(int mask = 1; mask > 0; mask <<= 1){
			if(mask & total_or)
				answer++;
		}

		cout << answer << nl;
	}

	return 0;
}