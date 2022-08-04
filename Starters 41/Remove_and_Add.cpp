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

		vector<int> A(N);
		FOR(i, N)
			cin >> A[i];

		map<int, int> index;
		int longest_length = 0;
		vector<int> l , r;
		for(int i = 0, j = 0; i < N; i++){
			j = max(index[A[i]], j);

			if(i - j + 1 > longest_length){
				longest_length = i - j + 1;
				r.clear();
				l.clear();
				r.push_back(i + 1);
				l.push_back(j + 1);
			}
			else if(i - j + 1 == longest_length){
				r.push_back(i + 1);
				l.push_back(j + 1);
			}

			index[A[i]] = i + 1;
		}
		int d1 = l[0] - 1, d2 = N - r[0];
		int answer = (d1 < d2) ? 2*d1 + d2 : 2*d2 + d1;
		for(int i = 0; i < l.size(); ++i){
			d1 = l[i];
			d2 = N - r[i];
			answer = min((d1 < d2) ? 2*d1 + d2 : 2*d2 + d1, answer);
		}

		cout << answer << nl;
	}

	return 0;
}