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
		map<int, int> H_freq;

		int height;
		FOR(i, N){
			cin >> height;
			H_freq[height]++;
		}
		int max_height = 0;
		for(auto& h: H_freq){
			h.second += h.first;
			if(h.second > max_height)
				max_height = h.second;
		}
		cout << max_height - 1 << nl;		
	}

	return 0;
}