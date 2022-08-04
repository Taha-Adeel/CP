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
		vector<int> a(n), b(n);
		map<p_ii, int> pair_freqs; 
		FOR(i, n){
			cin >> a[i];
		}
		FOR(i, n){
			cin >> b[i];
			pair_freqs[{a[i], b[i]}]++;
		}
		vector<int> a_copy = a, b_copy = b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool sortable = true;
		FOR(i, n){
			if(--pair_freqs[{a[i], b[i]}] < 0)
				sortable = false;
		}
		if(sortable){
			vector<p_ii> swaps;
			FOR(i, n - 1){
				FOR(j, n - i - 1){
					if ((a_copy[j] > a_copy[j + 1]) || b_copy[j] > b_copy[j + 1]){
						swap(a_copy[j], a_copy[j + 1]);
						swap(b_copy[j], b_copy[j + 1]);
						swaps.push_back({j, j + 1});
					}
				}
			}
			cout << swaps.size() << nl;
			for(auto& move: swaps)
				cout << move.first + 1 << ' ' << move.second + 1 << nl;		
		}
		else
			cout << -1 << nl;
	}

	return 0;
}