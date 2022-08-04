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
	FOR(t, T){
		int N, L;
		cin >> N >> L;

		vector<int> P(N);
		vector<bool> D(N);
		vector<bool> fallen(N, false);
		int fallen_count = 0;
		map<int, list<int>> stick;
		int p, d;
		FOR(i, N){
			cin >> p >> d;
			P[i] = 2 * p;
			D[i] = d;
			stick[P[i]].push_back(i);
		}
		cout << "Case #" << t + 1 << ": ";
		while(fallen_count < N){
			vector<int> fallen_ants_t;
			FOR(i, N){
				if(!fallen[i]){
					stick[P[i]].remove(i);
					P[i] += ((D[i])?1:-1);
					if(P[i] > 2 * L || P[i] < 0){
						fallen_ants_t.push_back(i);
						fallen[i] = true;
						fallen_count++;
						continue;
					}
					if(stick[P[i]].empty())
						stick[P[i]].push_back(i);
					else{
						D[stick[P[i]].front()] = !D[stick[P[i]].front()];
						D[i] = !D[i];
						stick[P[i]].push_back(i);
					}
				}
			}
			sort(fallen_ants_t.begin(), fallen_ants_t.end());
			for(auto ant: fallen_ants_t)
				cout << ant + 1 << ' ';
		}		
		cout << nl;
	}

	return 0;
}